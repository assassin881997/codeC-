#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

//cau truc word gom tu,dong,tro den 2 con tro left,right

int gtBam[1000]; // gia tri bam[0] la bien dem

struct word {
    int line;
    char data[25];
	struct word *left,*right;	
};
   
struct word *root[675];

char word[255];
// ham chuyen thanh mot xau chi gom cac tu duoc ngan cach nhau boi cac khoang trang
void read_line(char words[]) {
    int i=0;
	while(1) {
	    if( words[i]==' '||words[i]==','||words[i]=='.'||words[i]=='?'||
			words[i]==':'||words[i]==';'||words[i]=='!'||words[i]=='\n' ) 
			{
				word[i]=' ';
			    i++;
		    }
		            
		if( words[i]!=' '&&words[i]!=','&&words[i]!='.'&&words[i]!='?'&&
			words[i]!=':'&&words[i]!=';'&&words[i]!='!'&&words[i]!='\n' ) 
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
	Buffer[i]=strtok(buff,s);							// ham strtok(buff,s) cat xau buff boi cac xau s va luu cac tu do vao Buffer
	while(Buffer[i]!=NULL) {
	    i++;
		counts++; 										// so tu tren mot dong duoc cat duoc luu trong counts
        Buffer[i]=strtok(NULL,s);
    }                                    
}

//ham bam 2 ki tu dau (cac ki tu a->z)
int hashFunc(char data[25]) {
	int hashValue;
	hashValue=(int(data[0])-97)*26 +int(data[1])-97;
	return hashValue;
}

//chen tu vao bang bam
void insertWord(char data[],int line) {
	struct word *current;								
	struct word *parent;								
	int len=strlen(data);
	for( int i=0;i<=len;i++)
	    data[i]=tolower(data[i]);
	int hashValue;     
	if(len==1) hashValue=int (data[0])-97;
	else hashValue=hashFunc(data);
	   
	struct word *link=(struct word*)malloc(sizeof(struct word));			//tao 1 link
	link->line=line;														//tro link toi line
	strcpy(link->data,data);
	link->left=NULL;														//tro link nay sang left
	link->right=NULL;														//tro link nay sang right
	   
	if( root[hashValue]==NULL) {
	   	root[hashValue]=link;
	}
	else {
	    current=root[hashValue];
	    parent=NULL;
		while(1) {
		   	parent=current;
			if( strcmp(data,parent->data)<=0) {
		   		current =current->left;
				if( current==NULL) {
					parent->left=link;
					break;
				}    	
			}
			else {
				current=current->right;
				if( current==NULL) {
				 	parent->right=link;
				 	break;
				}
			}
		}	 
	}	   	   
}    

int solan=0;
int line[100];
//tim tu trong bang bam
void search(char data[]) {
	int hashValue;
	if(strlen(data)==1) 
	{
		hashValue=int (data[0])-97;
		gtBam[gtBam[0]++] = hashValue;
	}
	else 
	{
		hashValue=hashFunc(data);
		gtBam[gtBam[0]++] = hashValue;
	}
	struct word *find= root[hashValue];
	while(find!=NULL) {
		if( strcmp(data,find->data)==0) {
	    	solan++;
	    	line[solan]=find->line;
			find=find->left;
		}
		else {
		    if( strcmp(data,find->data)<0) find=find->left;
		    else find=find->right;
		}
	}  
}

main() {
	gtBam[0] = 1;
    int count=0,i;
    char buff[255],temp[255];
    char tukhoa[25],temp1[25];
    printf("HASH TABLE VERSION\n-----------------\n");
    
    FILE *fp;
    //doc file van ban
    fp = fopen("VanBan.txt", "rt");     
    while(1) {
	    count++; 												// bien count de luu so dong
        fgets(buff, 255, (FILE*)fp); 							// doc tung dong mot
        if(strcmp(temp,buff)==0) break;							// neu dong do da duoc doc tu truoc thi break
        strcpy(temp,buff); 										
        printf("\n Dong %d: %s\n",count, buff );
        read_line(buff);										// goi ham read_line de chuyen het ve xau cac tu ngan cach boi dau cham
        read_word(word); 										// cat ra thanh tung tu
	    for(int j=0;j<counts;j++)
	        insertWord(Buffer[j],count); 						// chen lan luot tung tu vao danh sach lien ket
	        counts=0;
    }       	
	fclose(fp);
	
	//doc file tu khoa
	fp=fopen("TuKhoa.txt","rt");
	printf("\n +-------------------+-------------------+-------------------+--------------------+");
    printf("\n | Tu khoa           | GT Bam            | So lan XH         | XH o dong          |");
    printf("\n +-------------------+-------------------+-------------------+--------------------+");
	int sl = 1;
	while(1) { 
		fscanf(fp,"%s",tukhoa);                          // doc tung tu khoa mot
	    if(strcmp(temp1,tukhoa)==0) break;               // neu tu khoa bi lap lai thi break
		strcpy(temp1,tukhoa);
	    search(tukhoa);                                // tim tu khoa 
	    //printf("\n | %-15s",tukhoa);
	    if(solan==0) {
//			printf("   | %d \t\t | 0\t\t    ",gtBam[sl++]);
//			printf(" | \t\t\t  |",tukhoa );
		}
        else  
			if(solan==1) {
				printf("\n | %-15s",tukhoa);
				printf("   | %d \t\t | 1\t\t",gtBam[sl++]);
				printf("     |%-3d \t\t  |",line[solan]);
			}
			else { 
				printf("\n | %-15s",tukhoa);
				printf("   | %-3d\t\t ",gtBam[sl++]);
				printf("| %-3d\t\t     ",solan); 
                int dem=0;
                printf("|");
                for(int j=1;j<=solan;j++) { 
					for(int k=j-1;k>=1;k--)
		            if(line[j]!=line[k]) dem++; 
					if(dem==j-1) printf("%-3d",line[j]);
					dem=0;
				}
			printf("\t  |");	
			}
        solan=0;   
	}   
	printf("\n +-------------------+-------------------+-------------------+--------------------+");
    fclose(fp);                 
}

