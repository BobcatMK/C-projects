#ifndef TEMPLATE_H
    #define TEMPLATE_H
    
    template <typename T>
    class Table {
        public:
            Table();
            Table(int m, int n);
            Table(int m, int n, const T& value);
            Table(const Table<T>& rhs);
            ~Table();

            Table<T>& operator=(const Table& rhs);
            void operator() (int i, int j, const T& value);
            T& operator() (int i, int j);
            
            int numRows() const;
            int numCols() const;

            void resize(int m, int n);
            void resize(int m, int n, const T& value);
            void changeValue(int i, int j, const T& value);

        private:
            // Make private because this method should only be used
            // internally by the class.
            void destroy();

        private:
            int mNumRows;
            int mNumCols;
            T** mDataMatrix;
    };

    // constructors
    template <typename T>
    Table<T>::Table() {
        mDataMatrix = 0;
        mNumRows = 0;
        mNumCols = 0;
    }

    template <typename T>
    Table<T>::Table(int m, int n) {
        mDataMatrix = 0;
        mNumCols = 0;
        mNumRows = 0;
        resize(m, n, T());
    }

    template <typename T>
    Table<T>::Table(int m, int n, const T& value) {
        mDataMatrix = 0;
        mNumCols = 0;
        mNumRows = 0;
        resize(m, n, value);
    }

    template <typename T>
    Table<T>::Table(const Table<T>& rhs) {
        mDataMatrix = 0;
        mNumCols = 0;
        mNumRows = 0;
        *this = rhs;
    }

    // destructor
    template <typename T>
    Table<T>::~Table<T>() {
        destroy();
    }

    // overloaded operators implementation
    template <typename T>
    Table<T>& Table<T>::operator=(const Table& rhs) {
        if (this == &rhs) return *this;

        resize(rhs.mNumRows, rhs.mNumCols);

        for (int i = 0; i < mNumRows; ++i)
            for (int j = 0; j < mNumCols; ++j)
                mDataMatrix[i][j] = rhs.mDataMatrix[i][j];

        return *this;
    }

    template <typename T>
    T& Table<T>::operator() (int i, int j) {
        return mDataMatrix[i][j];
    }

    template <typename T>
    void Table<T>::operator() (int i, int j, const T& value) {
        mDataMatrix[i][j] = value;
    }

    template <typename T>
    void Table<T>::changeValue(int i, int j, const T& value) {
        mDataMatrix[i][j] = value;
    }

    // methods implementation
    template <typename T>
    int Table<T>::numRows() const {
        return mNumRows;
    }

    template <typename T>
    int Table<T>::numCols() const {
        return mNumCols;
    }

    template <typename T>
    void Table<T>::resize(int m, int n) {
        resize(m, n, T());
    }

    template <typename T>
    void Table<T>::resize(int m, int n, const T& value) {
        destroy();

        mNumRows = m;
        mNumCols = n;

        mDataMatrix = new T*[mNumRows];

        for (int i = 0; i < mNumRows; ++i) {
            mDataMatrix[i] = new T[mNumCols];

            for (int j = 0; j < mNumCols; ++j) {
                mDataMatrix[i][j] = value;
            }
        }
    }

    template <typename T>
    void Table<T>::destroy() {
        if (mDataMatrix) {
            for (int i = 0; i < mNumRows; ++i) {
                if (mDataMatrix[i]) {
                    delete[] mDataMatrix[i];
                    mDataMatrix[i] = 0;
                }
            }

            delete[] mDataMatrix;
            mDataMatrix = 0;
        }

        mNumRows = 0;
        mNumCols = 0;
    }

#endif
