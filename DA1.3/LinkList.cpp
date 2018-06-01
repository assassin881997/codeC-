#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

//mot node gom dong,tu,con tro next
struct node { 
	int line;
    char data[25];
    struct node *next;  
};
            
struct node *head=NULL;
struct node *find=NULL;

char word[255];
// ham chuyen thanh mot xau chi gom cac tu duoc ngan cach nhau boi cac khoang trang
void read_line(char words[]) {	
	int i=0;
	while(1) { 
		if( words[i]==' '||words[i]==','||words[i]=='.'||words[i]=='?'||
	        words[i]==':'||words[i]==';'||words[i]=='!'||words[i]=='\n')     
			{ 
				word[i]=' ';
				i++;
		    }
		if( words[i]!=' '&&words[i]!=','&&words[i]!='.'&&words[i]!='?'&&
			words[i]!=':'&&words[i]!=';'&&words[i]!='!'&&words[i]!='\n')     
			{ 
				word[i]=words[i];
	            i++;
	        }
		if(words[i]=='\0') break;
	}
	word[i]=NULL;        
}

int counts=0;
char *Buffer[30];
// ham cat xau vua chuyen duoc thanh cac tu rieng re
void read_word(char buff[]) {	
	int i=0;
	const char s[2]=" ";
	Buffer[i]=strtok(buff,s);								// ham strtok(buff,s) cat xau buff boi cac xau s va luu cac tu do vao Buffer
	while (Buffer[i]!=NULL) {  
		i++;
		counts++;											// so tu tren mot dong duoc cat duoc luu trong counts
		Buffer[i]=strtok(NULL,s);
	}                                    
}

int solan=0,line[100];
void insertfirst( char Buffer[],int line ) { 						
	struct node *link=(struct node*)malloc(sizeof(struct node));	//tao 1 link
    strcpy(link->data,Buffer);
    link->line=line;
    link->next=head;												//tro link nay toi head cu
    head=link;														//tro link toi head moi
}
	    		    	
void search(char data[]) { 
	find=head;														//bat dau tim tu head 
    int len;
    while(find!=NULL) { 											//trong khi chua duyet het dslk
		len= strlen(find->data);									
        for(int i=0;i<=len;i++)
    	find->data[i]=tolower(find->data[i]);
		if(strcmp(find->data,data)==0) { 							//neu day la last node
			solan++;
			line[solan]=find->line;
        }
		find=find->next;											//tim kiem toi next find                    
	}	 	 	 
}	    	

main() { 
	int count=0,i;														
    char buff[300],temp[300];											
    char tukhoa[25],temp1[25];											
    printf("LINK_LIST VERSION\n-----------------\n");
    
	FILE *fp;
    fp = fopen("VanBan.txt", "rt");
    while(1) { 
		count++;													// bien count de luu so dong
        fgets(buff, 300, (FILE*)fp);								// doc tung dong mot
        if(strcmp(temp,buff)==0) break;								// neu dong do da duoc doc tu truoc thi break
        strcpy(temp,buff);
        printf("\n Dong %d: %s\n",count, buff );
        read_line(buff);											// goi ham read_line de chuyen het ve xau cac tu ngan cach boi dau cham
        read_word(word);											// cat ra thanh tung tu
        for(int j=0;j<counts;j++)
	    	insertfirst(Buffer[j],count);							// chen lan luot tung tu vao danh sach lien ket
	    counts=0;
    }      
    fclose(fp);
    
    fp=fopen("TuKhoa.txt","rt");
    printf("\n +---------------------------------------+-------------------+--------------------+");
    printf("\n | Tu khoa                               | So lan XH         | XH o dong          |");
    printf("\n +---------------------------------------+-------------------+--------------------+");
	while(1) { 
		fscanf(fp,"%s",tukhoa);										// doc tung tu khoa mot
        if(strcmp(temp1,tukhoa)==0) break;							// neu tu khoa bi lap lai thi break
        strcpy(temp1,tukhoa);
    	search(tukhoa);												// tim tu khoa 
//        printf("\n | %-15s",tukhoa);
		if(solan==0) {
		//	printf("      \t\t | 0\t\t    ");
		//	printf(" | \t\t\t  |",tukhoa );
		}
        else  
			if(solan==1) { 
			        printf("\n | %-15s",tukhoa);
				printf("      \t\t | 1\t\t");
				printf("     |%-3d \t\t  |",line[solan]);
			}
			else { 
			        printf("\n | %-15s",tukhoa);
				printf("     \t\t\t ");
				printf("| %-3d\t\t     ",solan); 
                int dem=0;
                printf("|");
                for(int j=solan;j>=1;j--) { 
					for(int k=j+1;k<=solan;k++)
		            if(line[j]!=line[k]) dem++; 
					if(dem==solan-j) printf("%-3d",line[j]);
					dem=0;
				}
			printf("\t  |");   
            }
        solan=0;     
    }
	printf("\n +---------------------------------------+-------------------+--------------------+");
    fclose(fp);       
}
