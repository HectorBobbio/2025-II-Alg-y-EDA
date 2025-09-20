#ifndef __VECTOR_H__
#define __VECTOR_H__

// PC1: deben hacer:
//      2 problemas de nivel 2
//      3 problemas de nivel 1
// Cada solucion enviarla como un Pull request

// TODO (Nivel 2): Agregar Traits

// TODO (Nivel 2): Agregar Iterators (forward, backward)

// TODO (Nivel 1): Agregar Documentacion para generar con doxygen

// TODO  (Nivel 2): Agregar control de concurrencia en todo el vector
template <typename T>
class CVector{
   
    T      *m_pVect = nullptr;
    size_t  m_count = 0; // How many elements we have now?
    size_t  m_max   = 0; // Max capacity

public:
    // DONE (Nivel 1) Agregar un constructor por copia
    CVector(CVector &v);

    CVector(size_t n);
    // DONE  (Nivel 2): Agregar un move constructor
    CVector(CVector &&v) noexcept;

    // DONE: (Nivel 1) implementar el destructor de forma segura
    virtual ~CVector();
    void insert(T &elem);
    void resize();
    T& operator[](size_t index);
};

template <typename T>
CVector<T>::CVector(size_t n) : m_pVect(nullptr), m_count(0), m_max(n){
    if (n > 0){
        m_pVect = new T[n];
    }
}

// DONE (Nivel 1) Agregar un constructor por copia.
template <typename T>
CVector<T>::CVector(CVector &v) : m_pVect(nullptr), m_count(v.m_count), m_max(v.m_max){
    // Vector vacío o inválido
    if (v.m_pVect == nullptr || m_max == 0){ 
        m_count = 0;
        m_max   = 0;
    }
    // Vector válido
    else{
        m_pVect = new T[m_max];
        for(size_t i=0; i < m_count ; ++i){
            m_pVect[i] = v.m_pVect[i];
        }
    }
}

// DONE (Nivel 2): Agregar un move constructor
template <typename T>
CVector<T>::CVector(CVector &&v) noexcept : m_pVect(v.m_pVect), m_count(v.m_count), m_max(v.m_max){
    if (m_pVect == nullptr || m_max == 0){
        m_pVect = nullptr;
        m_count = 0;
        m_max   = 0;
    }
    else{
        v.m_count = 0;
        v.m_max   = 0;
        v.m_pVect = nullptr;
    }
}

// DONE: (Nivel 1) implementar el destructor de forma segura (DONE)
template <typename T>
CVector<T>::~CVector(){
    delete [] m_pVect;
    m_pVect = nullptr;
    m_count = 0;
    m_max   = 0;
}

// TODO (Nivel 1): hacer dinamico el delta de crecimiento
template <typename T>
void CVector<T>::resize(){
    T *pTmp = new T[m_max+10];
    for(auto i=0; i < m_max ; ++i)
        pTmp[i] = m_pVect[i];
    delete [] m_pVect;
    m_max += 10;
    m_pVect = pTmp;
}

// TODO (ya está hecha): la funcion insert debe permitir que el vector crezca si ha desbordado
template <typename T>
void CVector<T>::insert(T &elem){
    if(m_count == m_max)
        resize();
    m_pVect[m_count++] = elem;
}

// DONE (Nivel 1) habilitar el uso de []
template <typename T>
T& CVector<T>::operator[](size_t index){
    return m_pVect[index];
}

#endif // __VECTOR_H__