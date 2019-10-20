#include <mpi.h>

#include <bits/stdc++.h>

using namespace std;


void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

int partition (int *arr, int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);  
}

void quicksort(int *arr, int lo, int hi) {
	if (lo < hi) {
		int p = partition(arr, lo, hi);
		quicksort(arr, lo, p-1);
		quicksort(arr, p + 1, hi);
	}
}

int sort_rec_seq(int* arr, int size){
    quicksort(arr,0,size-1);
}

int sort_recursive(int *arr, int size, int pr_rank, int max_rank, int rank_index){
	if(size == 0){
        return 0;
    }
    MPI_Status dtIn;
	int share_pr = pr_rank + pow(2, rank_index); /* Calculate the rank of sharing process*/
	rank_index++;		/*Increment the count index*/
	if(share_pr > max_rank){    		/*If no process to share sequentially*/
	    sort_rec_seq(arr, size);
		return 0;
	}

	int partition_pt = partition(arr, 0, size-1);    	/* partition array */
    int left_size = partition_pt;
    int right_size = size - (partition_pt + 1);

/* Send partition based on size, sort the remaining partitions,
receive sorted partition */
	
	if (left_size > right_size){  // send right part to other process
		if(right_size != 0){
            MPI_Send((arr + partition_pt + 1), right_size, MPI_INT, share_pr, 0, MPI_COMM_WORLD);
        }
        sort_recursive (arr, left_size, pr_rank, max_rank,rank_index);
		if(right_size != 0){
            MPI_Recv((arr + partition_pt + 1), right_size, MPI_INT, share_pr, MPI_ANY_TAG, MPI_COMM_WORLD, &dtIn);
        }
	}
	else{
        if(left_size != 0){
		    MPI_Send(arr, left_size, MPI_INT, share_pr , 0, MPI_COMM_WORLD);
        }
		sort_recursive ((arr + partition_pt + 1), right_size, pr_rank, max_rank, rank_index);
		if(left_size != 0){
            MPI_Recv(arr, left_size, MPI_INT, share_pr, MPI_ANY_TAG, MPI_COMM_WORLD, &dtIn);
        }
	}
}


int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);
    int total_processes;
    int process_rank;
    MPI_Comm_size( MPI_COMM_WORLD, &total_processes );
    MPI_Comm_rank( MPI_COMM_WORLD, &process_rank );
    MPI_Status status;

    int rankPower = 0;
	while (pow(2, rankPower) <= process_rank){
        rankPower++;
    }

    if(process_rank == 0){
        //cout<<"total processes is "<<total_processes<<"\n";
        int size = atoi(argv[1]);
        //cout<<"size is "<< size<<" "<<argc<<"\n";
        if(argc != size + 2){
            cout<<"number of elements entered not same as size\n";
            MPI_Abort(MPI_COMM_WORLD, MPI_ERR_COUNT);  // end all processes as input is not correct.    
        }
        int *arr = (int*)malloc(size * sizeof(int));
        int ind =0;
        for(int i=2;i<argc;i++){
            arr[ind] = atoi(argv[i]);
            ind++;
        }
        sort_recursive(arr,size,process_rank,total_processes-1,rankPower);
        cout<<"sorted array is \n";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        MPI_Abort(MPI_COMM_WORLD, MPI_SUCCESS);  // end all processes as sorting is complete.
    }
    else{
        int size;
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        // Capturing size of the array to receive
        MPI_Get_count(&status, MPI_INT, &size);
        
        int source_process = status.MPI_SOURCE;
        int *arr = (int*)malloc(size * sizeof(int));
        //cout<<process_rank<<" received "<< size<<" number of elements from "<<source_process<<"\n";
        MPI_Recv(arr, size, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sort_recursive(arr, size, process_rank, total_processes - 1, rankPower);
        MPI_Send(arr, size, MPI_INT, source_process, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
