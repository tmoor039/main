// should consider revising this read function
// array takes in a 20 character char... hard coded should revise to be dynamic
// Reviewed 5 April 2018

int openSequenceFile( char genomeName[20] ) //receives the file name to be opened
{
    if( ( fpgenomeFile = fopen(genomeName,"r") ) == NULL)
    {
        printf("\n %s failed to OPEN\n", genomeName);
        exit(0); //terminates program
    } 
  
    printf("\n   Getting %s genome... \n", genomeName );

    //find length of sequences in data file 
    char c;

    while( (c = getc(fpgenomeFile) ) != EOF ) 
    {    
        genomeLen++; //count bases in mr51TargetDataArray
    } 
    fclose(fpgenomeFile);
 
    //creates array in heap of genemeLen length, to load genome sequences
    genomeArray = malloc( sizeof(int) * genomeLen ); 

    //open target File again to read data into array
    if((fpgenomeFile=fopen(genomeName,"r"))==NULL) 
    { 
        printf("\n %s failed to OPEN\n", genomeName); 
        return 0; //exits this function
    } 

    int i=0;
    while( ( c = getc(fpgenomeFile) ) != EOF)  //reads data from file
    {  
        genomeArray[i]=c;  //load entire sequence in file into array 
        i++; 
    } 
    fclose(fpgenomeFile);

    printf("   There are %d bases in %s\n\n", genomeLen, genomeName ); 
    printf("   Creating Indexes, please wait .....\n");

}//end int openSequenceFile( char genomeName[20] )
