#include <stdio.h>
#include <stdlib.h>

int main ( int argc , char ** argv ) {
	if ( argc == 1 ) {
		printf ( "Please give a program to break apart into hex" );
		return 0;
	}
	FILE * fp = fopen ( argv[1] , "r" );

	fseek ( fp , 0 , SEEK_END );

	long len = ftell ( fp );

	unsigned char * file = (unsigned char *)malloc ( len * sizeof (unsigned char) );
	rewind ( fp );
	fread ( file , sizeof(unsigned char) , len , fp );

	fclose ( fp );

	fp = fopen ( "output" , "w+" );

	long i;
	printf ( "SIZE: %ld\n" , len );
	for ( i = 0 ; i < len ; i ++ ) {
		fprintf ( fp, "%#x," , file[i] );
	}

	fclose ( fp );

	return 0;
}