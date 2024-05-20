#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sortAndShuffle.h"

/*
* This method sorts the artists alphabetically. It takes as input:
* - sortedArtists: the array of artists that that should be sorted
* - numOfArtists: the total number of artists
*
*/
void sortArtists(char sortedArtists[][80] , int numOfArtists)
{
		int i =0;
	    int j=0;
	    int minIndex = 0;
	    int minIndexChanged = 0;

	    char swap [80];

	    for(i=0; i< (numOfArtists-1); i ++){
	        minIndex = i;
	        for(j=i+1; j<numOfArtists; j++){
	            if(strcmp(sortedArtists[j], sortedArtists[minIndex]) < 0){
	                minIndex = j;
	                minIndexChanged =1;
	            }
	        }

	            if(minIndexChanged == 1){
	                memset(swap, '$', 79);
	                swap[79] = '\0';
	                strcpy(swap,sortedArtists[i]);
	                strcpy(sortedArtists[i], sortedArtists[minIndex]);
	                strcpy(sortedArtists[minIndex], swap);
	                minIndexChanged =0;
	            }

	    }

}

/*
* This method sorts the songs of a specific artist alphabetically. It takes as input:
* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
* - numSongsPerArtists: the number of Songs for that specific artist
*/
void sortSongs(char songsOfAnArtist[][80] , int numSongsPerArtist)
{
		int i =0;
	    int j=0;
	    int minIndex = 0;
	    int minIndexChanged = 0;

	    char swap [80];

	    for(i=0; i< (numSongsPerArtist-1); i ++){
	        minIndex = i;
	        for(j=i+1; j<numSongsPerArtist; j++){
	            if(strcmp(songsOfAnArtist[j], songsOfAnArtist[minIndex]) < 0){
	                minIndex = j;
	                minIndexChanged =1;
	            }
	        }

	            if(minIndexChanged == 1){
	                memset(swap, '$', 79);
	                swap[79] = '\0';
	                strcpy(swap,songsOfAnArtist[i]);
	                strcpy(songsOfAnArtist[i], songsOfAnArtist[minIndex]);
	                strcpy(songsOfAnArtist[minIndex], swap);
	                minIndexChanged =0;
	            }

	    }

}

/*
* This method shuffles a set of songs. It takes as input:
* - songsToBeShuffled: the array of the songs that should be shuffled
* - numOfSongs: the number of songs to be shuffled
*/
void shuffleSongs(char array[][163], int numOfSongs){
	srand(time(NULL));
	int j;
	for(int i = 1; i < numOfSongs; i++)
	{
		char swap[163];
		j = rand()% (i+1);
		if(j!=i)
		{
			strcpy(swap,array[j]);
			strcpy(array[j], array[i]);
			strcpy(array[i],swap);
		}
	}
}


