template < typename T >
struct Noeud {
	T* objet = nullptr;
	Noeud<T>* suivant = nullptr;
	Noeud<T>* precedent = nullptr;
};
