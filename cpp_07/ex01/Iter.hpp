#ifndef ITER_H
# define ITER_H

template <typename A, typename L, typename Func>
void	iter(A *a, L const b, Func f) {
	for (L i = 0; i < b; i++) {
		f(a[i]);
	}
}

#endif