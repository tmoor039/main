/* This program sums all rows in an array using MPI parallelism.
    * The root process acts as a master and sends a portion of the
    * array to each child process.  Master and child processes then
    * all calculate a partial sum of the portion of the array assigned
    * to them, and the child processes send their partial sums to 
    * the master, who calculates a grand total.
    **/

   #include <stdio.h>
   #include <mpi.h>

   int my_id, root_process, ierr, num_procs, an_id;
   MPI_Status status;
   
   root_process = 0;

   /* Now replicate this process to create parallel processes.  

   ierr = MPI_Init(&argc, &argv);

   /* find out MY process ID, and how many processes were started */

   ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
   ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

   if(my_id == root_process) {
      /* I must be the root process, so I will query the user
       * to determine how many numbers to sum.

       * initialize an array,

       * distribute a portion of the array to each child process,

       * and calculate the sum of the values in the segment assigned 
       * to the root process,

       * and, finally, I collect the partial sums from slave processes,
       * print them, and add them to the grand sum, and print it */
   }

   else {

      /* I must be slave process, so I must receive my array segment,

       * calculate the sum of my portion of the array,

       * and, finally, send my portion of the sum to the root process. */

   }

   /* Stop this process */

   ierr = MPI_Finalize();
}

