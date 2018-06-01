#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

//mot node gom tu, dong, hai con tro
struct node { 
	char data[25];
    int line;
    struct node *left,*right;
}; 

struct node *root;            

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
	Buffer[i]=strtok(buff,s);                                 // ham strtok(buff,s) cat xau buff boi cac xau s va luu cac tu do vao Buffer
	while(Buffer[i]!=NULL){ 
		i++;
		counts++;                                             // so tu tren mot dong duoc cat duoc luu trong counts
        Buffer[i]=strtok(NULL,s);
    }                                    
}

// ham chen mot tu vao mot node tren cay nhi phan 		    
void insertnode(char data[],int line) { 
	struct node *current;
    struct node *parent;
    int len=strlen(data);                                     // chuyen ki tu hoa thanh ki tu thuong
    for(int i=0;i<=len;i++)
       data[i]=tolower(data[i]);
    
	struct node *link=(struct node*)malloc(sizeof(struct node));   // khai bao mot link
	link->line=line;                                          // lay thong cho node tu du lieu truyen vao                                   
	strcpy(link->data,data);
	link->left=NULL;
	link->right=NULL;
			         
    if(root==NULL)                                            // neu cay rong thi cho link lam goc
       root=link; 
	else { 
		current=root;                                         // neu cay ko rong thi cho duyet bat dau tu goc
		parent=NULL;
		while(1) { 
			parent=current;                                  // ghi nho nut dang duoc kiem tra
			if(strcmp(data,parent->data)<=0) {               // neu tu cua node xep truoc tu cua nut dang xet 
				current=current->left;                       // chuyen xuong nui trai cua nut day
				if(current==NULL) {                          // neu tim duoc nut null
					parent->left = link;                     // noi node voi nut cha
					break; 
				}   
			}
			else { 
				current=current->right;                      // neu tu cua node xep sau tu cua nut dang xet thi chuyen xuong nut phai
				if(current==NULL) {                          // neu tim thay nut null
					parent->right=link;                      // noi node voi nut cha;
					break; 
				}
			}   
		}      		            	     
	}
}

int solan=0;
int line[100];
// ham tim kiem tren cay nhi phan
void search(char data[]) {                             
    struct node *find=root;                              // cho bat dau duyet tu nut goc
    while(find!=NULL) {                                  // trong khi chua duyet het cay
		if(strcmp(data,find->data)==0) {                 //neu tim thay tu can tim
            solan++;                                     // tang so lan tim thay
            line[solan]=find->line;   				     // ghi nho cac dong da tim thay
            find=find->left;                             // di chuyen xuong cay con trai
		}
		else 
			if(strcmp(data,find->data)<0)                // di chuyen xuong cac cay de tim kiem tiep
		    	find=find->left;
			else find=find->right;	     
	}
}

main() { 
	int count=0,i;
    char buff[255],temp[255];
    char tukhoa[25],temp1[25],tukhoa1[25];
    printf("TREE VERSION\n-----------------\n");
    
	FILE *fp;
    fp = fopen("VanBan.txt", "rt");
    while(1) {
		count++;                                         // bien count de luu so dong
        fgets(buff, 300, (FILE*)fp);                     // doc tung dong mot
        if(strcmp(temp,buff)==0) break;                  // neu dong do da duoc doc tu truoc thi break
        strcpy(temp,buff); 
        printf("\n Dong %d: %s\n",count, buff );
        read_line(buff);                                 // goi ham read_line de chuyen het ve xau cac tu ngan cach boi dau cham
        read_word(word);                                 // cat ra thanh tung tu
	    for(int j=0;j<counts;j++)
	        insertnode(Buffer[j],count);                 // chen lan luot tung tu vao cay nhi phan
	    counts=0;
    }
    fclose(fp);
	
	fp=fopen("TuKhoa.txt","rt");
	printf("\n +---------------------------------------+-------------------+--------------------+");
    printf("\n | Tu khoa                               | So lan XH         | XH o dong          |");
    printf("\n +---------------------------------------+-------------------+--------------------+");
	while(1) { 
	
		fscanf(fp,"%s",tukhoa);                          // doc tung tu khoa mot
	    if(strcmp(temp1,tukhoa)==0) break;               // neu tu khoa bi lap lai thi break
	    strcpy(temp1,tukhoa);
	    search(tukhoa);                                // tim tu khoa  
	    
//	    printf("\n | %-15s",tukhoa);
	    if(solan==0) {
//			printf("      \t\t | 0\t\t    ");
//			printf(" | \t\t\t  |",tukhoa );
		}
        else  
			if(solan==1) { printf("\n | %-15s",tukhoa);
				printf("      \t\t | 1\t\t");
				printf("     |%-3d \t\t  |",line[solan]);
			}
			else { printf("\n | %-15s",tukhoa);
				printf("     \t\t\t ");
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
	printf("\n +---------------------------------------+-------------------+--------------------+");
	printf("\nNhap tu khoa:"); scanf("%s",&tukhoa1);
	search(tukhoa1);
	printf("\nTu khoa %s",tukhoa1);
	printf("Xuat hien %d lan",solan);
    fclose(fp);                 
}
