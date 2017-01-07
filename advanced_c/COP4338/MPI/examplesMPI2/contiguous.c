#include "mpi.h"
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int myrank;
    MPI_Status status;
    MPI_Datatype type;
    int buffer[100];
    int i;	
 
    MPI_Init(&argc, &argv);
 
    MPI_Type_contiguous( 100, MPI_INT, &type );
    MPI_Type_commit(&type);
 
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
 
    if (myrank == 0)
	
    {
	for(i=0;i<100;i++) 
        {
		buffer[i]=i;
	}
        MPI_Send(buffer, 1, type, 1, 1, MPI_COMM_WORLD);
    }
    else if (myrank == 1)
    {
        MPI_Recv(buffer, 1, type, 0, 1, MPI_COMM_WORLD, &status);
        for(i=0;i<100;i++) 
        {
		printf("%d\n",buffer[i]);
	}
        
    }
 
    MPI_Finalize();
    return 0;
}

