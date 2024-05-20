//Wong Soong Way (23206317)
#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

int main(void)
{
	setbuf(stdout,NULL);
		//The array containing artists names
		char artists[4][80]= {"Taylor Swift", "The Cranberries", "U2", "Lorde"};
		//The array containing the sorted artists
		char sortedArtists[4][80];
		//Songs for Artist 1
		char songsArtist1[3][80]= {"Shake it Off", "Bad Blood", "Anti-Hero"};
		//Songs for Artist 2
		char songsArtist2[3][80]= {"Zombie","Salvation", "In the End"};
		//Songs for Artist 3
		char songsArtist3[3][80]= {"With or Without you", "One", "Beautiful Day"};
		//Songs for Artist 4
		char songsArtist4[3][80]= {"Green Light", "The Louvre", "Tennis Court"};
		//The total number of artists (Note it can be less than 4)
		int numOfArtists=4;
		//The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
		int numSongsPerArtist[4]= {3,3,3,3};
		// The array containing the songs to be shuffled
		char songsToBeShuffled[24][163];
		int numOfSongs =0;


	// this is the start of getting user input
	for(int i = 4; i <4; i++)
	{
		if(i>0)
			printf("\nInsert an artist/group name:\n");
		else
			printf("Insert an artist/group name:\n");

		fgets(artists[numOfArtists],80, stdin);

		if(artists[numOfArtists][1] == '\n')
			break;

		for(int j = 0; j < 3; j++)
			{
				printf("Insert song %d for %s", j+ 1, artists[numOfArtists]);


				switch(numOfArtists)
				{
					case 0:
						fgets(songsArtist1[j],80, stdin);
						if(songsArtist1[j][1] == '\n')
						{j=3;break;}
						numSongsPerArtist[numOfArtists]++;
						break;
				  	case 1:
						fgets(songsArtist2[j],80, stdin);
						if(songsArtist2[j][1] == '\n')
						{j=3;break;}
						numSongsPerArtist[numOfArtists]++;
						break;
				  	case 2:
						fgets(songsArtist3[j],80, stdin);
						if(songsArtist3[j][1] == '\n')
						{j=3;break;}
						numSongsPerArtist[numOfArtists]++;
				  		break;
				  	case 3:
				  		fgets(songsArtist4[j],80, stdin);
				  		if(songsArtist4[j][1] == '\n')
				  		{j=3;break;}
				  		numSongsPerArtist[numOfArtists]++;
				  		break;
				}
			}
		numOfArtists++;
	}
	//this is the end of getting user input and assigning the respective values


	//this counts the number of songs
	for (int i = 0; i< numOfArtists; i++)
	{
		numOfSongs += numSongsPerArtist[i];
	}
	numOfSongs *= 2; // multipy the total number of songs by 2 because each songs has to be played twice

	// this copies artists[][] into sortedArtists[][] which will be sorted
	for(int i = 0; i< numOfArtists; i++)
		{
			strcpy(sortedArtists[i], artists[i]);
		}

	//this sorts sortedArtists[][] which hasn't be sorted yet
	sortArtists(sortedArtists,numOfArtists);

	//this sorts the songs of each artists
		for (int i = 0; i < numOfArtists; i++)
		{
			switch(i)
			{
				case 0:
					sortSongs(songsArtist1, numSongsPerArtist[0]);
					break;
				case 1:
					sortSongs(songsArtist2,numSongsPerArtist[1]);
					break;
				case 2:
					sortSongs(songsArtist3,numSongsPerArtist[2]);
					break;
				case 3:
					sortSongs(songsArtist4,numSongsPerArtist[3]);
					break;

			}

		}

	//prints out the artist/group name and the song title both in alphabetical order
	printf("Sorted list of songs:");

	printf("\n");

	for (int i = 0; i < numOfArtists; i++)
	{
		for(int j = 0; j< numOfArtists; j++)
		{
			if(strcmp(sortedArtists[i],artists[j])==0)
			{
				printf("%s", sortedArtists[i]);
				printf("\n");
				for(int a = 0; a < numSongsPerArtist[j]; a++)
				{
					switch(j)
					{
						case 0:
							printf("\t- %s", songsArtist1[a]);
							printf("\n");
							break;
						case 1:
							printf("\t- %s", songsArtist2[a]);
							printf("\n");
							break;
						case 2:
							printf("\t- %s", songsArtist3[a]);
							printf("\n");
							break;
						case 3:
							printf("\t- %s", songsArtist4[a]);
							printf("\n");
							break;
					}

				}
			}
		}
		printf("\n");
	}
	//end of printing them in alphabetical order


	//filling the songsToBeShuffled array with totalNumOfSongs *2 because each songs has to be played twice
	for(int i = 0, counter= 0; i< numOfArtists; i++)
	{
		for (int b = 0; b < numSongsPerArtist[i];b++)
		{
			for(int j= 0; j <2 ; j++)
					{
						char temp[163];
						switch(i)
						{
							case 0:
								strcpy(temp, artists[i]);
								strcat(temp, " - ");
								strcat(temp, songsArtist1[b]);
								strcpy(songsToBeShuffled[counter++],temp);
								break;
							case 1:
								strcpy(temp, artists[i]);
								strcat(temp, " - ");
								strcat(temp, songsArtist2[b]);
								strcpy(songsToBeShuffled[counter++],temp);
								break;
							case 2:
								strcpy(temp, artists[i]);
								strcat(temp, " - ");
								strcat(temp, songsArtist3[b]);
								strcpy(songsToBeShuffled[counter++],temp);
								break;
							case 3:
								strcpy(temp, artists[i]);
								strcat(temp, " - ");
								strcat(temp, songsArtist4[b]);
								strcpy(songsToBeShuffled[counter++],temp);
								break;


						}

					}
		}
	}
	//end of filling the array


	int bool = 0, consec = 0;
	while(bool!= numOfSongs -1)
		{
			shuffleSongs(songsToBeShuffled, numOfSongs);
			bool = 0;
			consec = 0;
			for (int i = 0; i <numOfSongs-1 && consec ==0; i++)
					{
				for(int j = i+1; j< i+6 && j<numOfSongs;j++)
				{
					if(!strcmp(songsToBeShuffled[i],songsToBeShuffled[j]))
					{
						consec= 1;
						break;
					}
				}
				if(consec==0 )
									{
										bool++;
									}
		}}

//this prints out the shuffled list
for (int i = 0; i< numOfSongs; i++)
printf("%s\n", songsToBeShuffled[i]);

  return 0;
}
