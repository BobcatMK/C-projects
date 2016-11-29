#include <Windows.h>
#include "resource.h"
#include "commdlg.h"
#include "Shobjidl.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

HWND hTextFileViewerDlg;

void OpenFileAndLoadContentToEditControl(HWND hFileContentEditControl, PWSTR filePath) {
	wifstream inFile(filePath);
	wstring lineOfText;
	wstring fileText;

	if (!inFile) return;

	while (!inFile.eof()) {
		getline(inFile, lineOfText);
		lineOfText += L"\r\n"; // this line is necessary because edit control does not see line feeds it only sees carriage return + line feed
		fileText += lineOfText.c_str();
	}

	inFile.close();

	SetWindowTextW(hFileContentEditControl, fileText.c_str());
}

void SaveFileWithContentFromEditControl(HWND hFileContentEditControl, PWSTR filePath) {
	wofstream outFile(filePath, ios_base::trunc);

	if (!outFile) return;

	int editControlTextLength = GetWindowTextLengthW(hFileContentEditControl) + 1;
	wchar_t* editControlText = new wchar_t[editControlTextLength];

	//GetWindowTextW(hFileContentEditControl, editControlContent, GetWindowTextLengthW(hFileContentEditControl) + 1);
	SendMessageW(hFileContentEditControl, WM_GETTEXT, WPARAM(editControlTextLength), LPARAM(editControlText));

	outFile << editControlText;
	delete[] editControlText;
	outFile.close();
}

BOOL CALLBACK TextFileViewerDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	UINT wParamLOWORD = LOWORD(wParam);

	static HWND hFileContentEditControl = 0;

	const COMDLG_FILTERSPEC fileTypesAllowed[1] = {
		{ L"Text files", L"*.txt" }
	};

	switch (msg) {
	case WM_INITDIALOG:
		hFileContentEditControl = GetDlgItem(hDlg, IDC_FILE_CONTENT);
		return true;
	case WM_COMMAND:
		switch (wParamLOWORD) {
		case IDC_OPEN:
			{
				IFileDialog* fileOpenDlg = nullptr;
				HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, 0, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&fileOpenDlg));

				if (SUCCEEDED(hr)) {
					hr = fileOpenDlg->SetFileTypes(1, fileTypesAllowed);
					if (SUCCEEDED(hr)) {
						hr = fileOpenDlg->Show(hTextFileViewerDlg);
						if (SUCCEEDED(hr)) {
							IShellItem* fileOpenDlgResult = nullptr;
							hr = fileOpenDlg->GetResult(&fileOpenDlgResult);

							if (SUCCEEDED(hr)) {
								PWSTR pszFilePath = 0;
								hr = fileOpenDlgResult->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

								if (SUCCEEDED(hr)) {
									OpenFileAndLoadContentToEditControl(hFileContentEditControl, pszFilePath);
								}
							}
							fileOpenDlgResult->Release();
						}
					}
				}
				fileOpenDlg->Release();

				return true;
			}
		case IDC_SAVE:
			IFileDialog* fileSaveDlg = nullptr;
			HRESULT hr = CoCreateInstance(CLSID_FileSaveDialog, 0, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&fileSaveDlg));

			if (SUCCEEDED(hr)) {
				hr = fileSaveDlg->SetFileTypes(1, fileTypesAllowed);
				if (SUCCEEDED(hr)) {
					hr = fileSaveDlg->SetDefaultExtension(L"txt");
					if (SUCCEEDED(hr)) {
						hr = fileSaveDlg->Show(hTextFileViewerDlg);
						if (SUCCEEDED(hr)) {
							IShellItem* fileSaveDlgResult = nullptr;
							hr = fileSaveDlg->GetResult(&fileSaveDlgResult);

							if (SUCCEEDED(hr)) {
								PWSTR pszFilePath = 0;
								hr = fileSaveDlgResult->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

								if (SUCCEEDED(hr)) {
									SaveFileWithContentFromEditControl(hFileContentEditControl, pszFilePath);
								}
							}
							fileSaveDlgResult->Release();
						}
					}
				}
			}
			fileSaveDlg->Release();

			return true;
		}
		return true;
	case WM_CLOSE:
		DestroyWindow(hDlg);
		return true;
	case WM_DESTROY:
		PostQuitMessage(0);
		return true;
	}

	return false;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd) {
	hTextFileViewerDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_TEXT_FILE_VIEWER), 0, TextFileViewerDlgProc);

	ShowWindow(hTextFileViewerDlg, showCmd);

	MSG msg;
	SecureZeroMemory(&msg, sizeof(MSG));

	while (GetMessage(&msg, 0, 0, 0)) {
		if (hTextFileViewerDlg == 0 || !IsDialogMessage(hTextFileViewerDlg, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return static_cast<int>(msg.wParam);
}
