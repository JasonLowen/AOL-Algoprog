#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char loc1[5000][100];
char loc2[5000][100];
int price[5000];
int room[5000];
int bathrooms[5000];
int carparks[5000];
char type[5000][100];
int area[5000];
char furnish[5000][100];
char string1[100];
char string2[100];
char string3[100];
char string4[100];
char string5[100];
char string6[100];
char string7[100];
char string8[100];
char string9[100];
char input[100];
int n = 0;

void readfile(){
	FILE *baca = fopen("file.csv", "r");
	if(baca == NULL){
		perror("Encountering error opening the file ");
	}
	fscanf(baca, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", string1, string2, string3, string4, string5, string6, string7, string8, string9);
	while(!feof(baca)){
		fscanf(baca, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n", &loc1[n], &loc2[n], &price[n], &room[n], &bathrooms[n], &carparks[n], &type[n], &area[n], &furnish[n]);
		n++;
	}
	fclose(baca);	
}

void search1(char loc1[][100], char loc2[][100], int price[], int room[], int bathrooms[], int carparks[], char type[][100], int area[], char furnish[][100], char data[], int n, int menu){
	printf("%-30s | %-15s | %-8s | %-7s | %-10s | %-10s | %-10s | %-5s | %-5s\n", "Location 1", "Location 2", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Area", "Furnish");
	int counter = 0;
	for(int i = 0; i < n; i++){
		if(menu == 1){
			if(strstr(loc1[i], data)){
			printf("%-30s | %-15s | %-8d | %-7d | %-10d | %-10d | %-10s | %-5d | %-5s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
			counter++;
			}
		}
		else if(menu == 2){
			if(strstr(loc2[i], data)){
			printf("%-30s | %-15s | %-8d | %-7d | %-10d | %-10d | %-10s | %-5d | %-5s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
			counter++;
			}	
		}
		else if(menu == 3){
			if(strstr(type[i], data)){
			printf("%-30s | %-15s | %-8d | %-7d | %-10d | %-10d | %-10s | %-5d | %-5s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
			counter++;
			}
		}
		else if(menu == 4){
			if(strstr(furnish[i], data)){
			printf("%-30s | %-15s | %-8d | %-7d | %-10d | %-10d | %-10s | %-5d | %-5s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
			counter++;
		}
		}
	}
	if(counter == 0){
			printf("\t\t\t\t\t\t\t %s", "|Data not found!|");
		}
}

void search2(char loc1[][100], char loc2[][100], int price[], int room[], int bathrooms[], int carparks[], char type[][100], int area[], char furnish[][100], char data[], int n, int menu){
	int x = atoi(data);
	printf("%-30s | %-15s | %-8s | %-7s | %-10s | %-10s | %-10s | %-5s | %-5s\n", "Location 1", "Location 2", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Area", "Furnish");
	for(int i = 0; i < n; i++){
		if(menu == 1){
			if(x == room[i]){
				printf("%-30s | %-15s | %-8d | %-7d | %-10d | %-10d | %-10s | %-5d | %-5s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
			}
		}
		else if(menu == 2){
			if(x == bathrooms[i]){
				printf("%-30s | %-15s | %-8d | %-7d | %-10d | %-10d | %-10s | %-5d | %-5s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
			}
		}
		else if(menu == 3){
			if(x == carparks[i]){
				printf("%-30s | %-15s | %-8d | %-7d | %-10d | %-10d | %-10s | %-5d | %-5s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
			}
		}
	}
}

int main(){
	
	readfile();
	char data[1000];
	char category[1000];
	printf("Category options : loc1, loc2, room, bathrooms, carparks, type, furnish\n");
	printf("Please input the data and category that you want to search :\n");
	scanf("%s in %s", data, category);
	if(strstr("loc1", category)){
		search1(loc1, loc2, price, room, bathrooms, carparks, type, area, furnish, data, n, 1);
	}
	else if(strstr("loc2", category)){
		search1(loc1, loc2, price, room, bathrooms, carparks, type, area, furnish, data, n, 2);
	}
	else if(strstr("room", category)){
		search2(loc1, loc2, price, room, bathrooms, carparks, type, area, furnish, data, n, 1);
	}
	else if(strstr("bathrooms", category)){
		search2(loc1, loc2, price, room, bathrooms, carparks, type, area, furnish, data, n, 2);
	}
	else if(strstr("carparks", category)){
		search2(loc1, loc2, price, room, bathrooms, carparks, type, area, furnish, data, n, 3);
	}
	else if(strstr("type", category)){
		search1(loc1, loc2, price, room, bathrooms, carparks, type, area, furnish, data, n, 3);
	}
	else if(strstr("furnish", category)){
		search1(loc1, loc2, price, room, bathrooms, carparks, type, area, furnish, data, n, 4);
	}
	
	return 0;
}
