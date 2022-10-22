#include <memory>

/*
 * clib_shared_ptr.h
 * Classe genérica para o uso de shared_ptr em estruturas de bibliotecas da linguagem c
 */

/*
 * T: Tipo do ponteiro
 * D: Classe a ser usada na destruição do shared_ptr
 *    O valor padrão pode atrapalhar em vez de ajudar
 */
template <typename T, typename D = std::default_delete<T>>
class clib_shared_ptr : std::shared_ptr<T> {
public:
    clib_shared_ptr(T* ptr = nullptr)
        : std::shared_ptr<T>{ ptr, D{} }
    { }

    void reset(T* ptr) {
        std::shared_ptr<T>::reset(ptr, D{});
    }

    operator T*() { return std::shared_ptr<T>::get(); }
};
