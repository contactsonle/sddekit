/* Apache 2.0 INS-AMU 2015 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sk_config.h"
#include "sk_util.h"

void sk_util_res_name(char *relname, char **absname) {
	*absname = malloc (1024);
	sprintf(*absname, "%s/%s", sk_res_dir, relname);
}

static int compare_int(const void *a, const void *b)
{
	if ( *(int*) a <  *(int*) b ) return -1;
	if ( *(int*) a == *(int*) b ) return  0;
	else /* a > b */ return  1;
}

int sk_util_fill_gauss(rk_state *rng, int nx, double *x)
{
	int i;

	for (i=0; i<nx; i++)
		x[i] = rk_gauss(rng);

	return 0;
}

int sk_util_uniqi(
	const int n, 
	const int * restrict ints, 
	int * restrict nuniq, 
	int ** restrict uints)
{ 
	int i, j, *ints_copy;

	if (n==0) return 0;

	if (n==1) {
		*nuniq = 1;
		SK_MALLOCHECK(*uints = malloc (sizeof(int)));
		(*uints)[0] = ints[0];
		return 0;
	}

	/* sort copy of input vector */
	SK_MALLOCHECK(ints_copy = (int*) malloc(sizeof(int) * n));
	memcpy(ints_copy, ints, n*sizeof(int));

	qsort(ints_copy, n, sizeof(int), compare_int);

	/* count uniq */
	*nuniq = 1;
	for (i=0; i<(n-1); i++)
		if (ints_copy[i] != ints_copy[i+1])
			(*nuniq)++;

	SK_MALLOCHECK(*uints = (int*) malloc (sizeof(int) * *nuniq));

	/* copy unique into output array */
	j = 0;
	(*uints)[j++] = ints_copy[0];
	for (i=0; i<(n-1); i++)
		if (ints_copy[i] != ints_copy[i+1])
			(*uints)[j++] = ints_copy[i+1];

	free(ints_copy);
	
	return 0;
}
