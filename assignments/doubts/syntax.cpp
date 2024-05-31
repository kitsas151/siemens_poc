template <typename IndexType, typename ValueType, class MemorySpace>
template <typename MatrixType>
csr_matrix<IndexType,ValueType,MemorySpace>&
csr_matrix<IndexType,ValueType,MemorySpace>
::operator=(const MatrixType& matrix)
{
    cusp::convert(matrix, *this);
    return *this;
}

template<typename X> //line no1
template<typename Y> temp<X> Classname<X>::operator(const Y &y)
{
        return *this;

}
