#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BP 128
#define SIZE 128 //256 //1024
#define MAX_ATT 10

struct buffer {
   unsigned char db;
   unsigned char pc;
   unsigned char nrec;
   unsigned char nbyt;
   char data[SIZE];
};

union c_float
{
	float flt;
	char   cflt[sizeof(float)];
};

union c_double
{
	double dbl;
	char   cdbl[sizeof(float)];
};

union c_int
{
	int  num;
	char cnum[sizeof(int)];
};

struct t_buf_content {
	char type;
	unsigned char len;
};

void initbuffer(struct buffer *bp)
{
	int i;
	printf("Initializing buffer ...\n");
	for (i=0;i<BP;i++)
  	{
	    //printf("%d",i+1);
		bp->db=0;
		bp->pc=0;
		bp->nrec=0;
		bp->nbyt=0;
		bp++;
		//printf("\b\b\b");
	}
	//printf("\n");
}

void copytup(struct buffer *bp,char *t, int pos)
{
	int i=pos;
	for (;i<pos+bp->nbyt;i++)
	     bp->data[i]=*(t++);
}
//
void fillbufpool(struct buffer *bp,char *t, unsigned char ttup)
{
	unsigned int i=0, found=0;
	//search for an available page in buffer
	while (!found && i < BP)
	{
    	int avail=bp[i].nrec==0?SIZE:SIZE-bp[i].nrec*ttup;
    	printf(">> Registers: %d Available bytes: %d\n",bp[i].nrec,avail);
	    if ((bp[i].nbyt==ttup || bp[i].nbyt==0)  && ttup < avail) found=1;
        i++;
    }
    if (found)
    {
		int rpos;
		--i;
		bp[i].nrec++;
		bp[i].nbyt=ttup;
		// find the next available position to copy the tuple
		rpos=(bp[i].nrec-1)*ttup;
	    copytup(&bp[i],t,rpos);
	    printf("*** %d %d pos: %d\n",i,bp[i].nrec,rpos);
		return;
    }
    // here we can implement buffer manager replacement policies
    printf("(Fatal error) No availabe room in the buffer!\n");
    return;
}

void cpystr(char *tg, char *sc, int st, int len)
{
	int i=st,j=0;
	for (;i<len+st;i++) {
	  tg[i]=sc[j++];
	}
}

void filltuple(char *tp, const void *v, unsigned char offs, struct t_buf_content bufc)
{
	char  *str=(char *)v;
	printf("Inserting data into the tuple: ");
	switch (bufc.type)
	{
	  case 'S': 
	          {
	            cpystr(tp,str,offs,bufc.len);
	            printf("%s\n",tp+offs);
	            break;
	          }
	  case 'I': 
	          {
            	int *i=(int *)v;
            	union c_int ci;
            	ci.num=*i;
	            cpystr(tp,ci.cnum,offs,bufc.len);
	            printf("%d\n",*i);
                break;
	          }
	  case 'F': 
	          {
                float *f=(float *)v;
                union c_float cf;
                cf.flt=*f;
		        cpystr(tp,cf.cflt,offs,bufc.len);
                printf("%f\n",*f);
                break;
	          }
	  case 'D':
	          {
	            double *d=(double *)v;
	            union c_double cd;
             	cd.dbl=*d;
	            cpystr(tp,cd.cdbl,offs,bufc.len);
	            printf("%lf\n",cd.dbl);
	            break;
	          }
	}
}

void printdebug(struct buffer *bp)
{
	int i=0;
	printf("\nBuffer Dump:\n");
	for (;i<BP;i++)
	{
	  printf("Page: %d\n",i+1);
	  if (bp[i].nrec > 0)
	  {
		printf("---%d %d\n",bp[i].nrec,bp[i].nbyt);  
      }	else printf("--- Empty\n");
    }
}

void showBuffer(struct buffer *bp, unsigned char tl, struct t_buf_content *bc, int p)
{
    int i=0, j;
    if (p<0 || p>=BP)
    { 
		printf("Invalid page number!\n");
		return;
	}
    char found0=0;
    j=0;
    int sgmt=0;
    for (;i<=bp[p].nrec;i++)
    {
        for (j=0;j<MAX_ATT && bc[j].type!='@';j++)
        {
			printf("\n%d %c %d seg: %d ",j,bc[j].type,bc[j].len,sgmt);
			switch (bc[j].type)
		     {
		      case 'S':
		           found0=0;
		           for (int k=0;k<bc[j].len;k++)
		           {
					   if (bp[p].data[sgmt]==0) found0=1;
					   if (!found0)
					      printf("%c",bp[p].data[sgmt]);
					   else 
					      printf(" ");
					   sgmt++;
				   }
				   break;
		      case 'I':
		           {
		              int *v=(int *)&bp[p].data[i];
		              printf("%6d",*v);
		              sgmt+=bc[j].len;
		              break;
			       }
		      case 'F':
		           {
		              float *v=(float *)&bp[p].data[i];
                      //printf("%ld",sizeof(*v));
		              printf("%f ",*v);
		              sgmt+=bc[j].len;
		              break;
			       }
		      case 'D':
		           {
		              double *v=(double *)&bp[p].data[i];
		              printf("%lf ",*v);
		              sgmt+=bc[j].len;
		              break;
			       }
		    }
	    }   
  	    printf("\n");
	}
	return;
}

int main()
{
	char *tuple=(char *)malloc(sizeof(char)*38); //tuple's length
	struct buffer *bufpool;
	struct t_buf_content buf_cont[MAX_ATT];
    
	unsigned char tup_len;
	float sal;
	int   i;
	printf("Starting buffer manager (%d pages)...\n",BP);
	bufpool=(struct buffer *)malloc(sizeof(struct buffer)*BP);
	if (bufpool==NULL)
	{
		printf("Out of memory for buffer pool!\n");
		return 0;
    }
    initbuffer(bufpool); 
    // tuples in the buffer are on the form: string 30 and float 4
    buf_cont[0].type='S';
    buf_cont[0].len=30;
    //buf_cont[1].type='S';
    //buf_cont[1].len=10;
    buf_cont[1].type='F';
    buf_cont[1].len=sizeof(float);
    buf_cont[2].type='@'; // fim de atributos 
    // tuple's size
    tup_len=buf_cont[0].len+buf_cont[1].len;
    printf("Tuple length: %d bytes\n",tup_len);
    //        tuple    value    type        start struct
    //          |        |        |         |      |
    filltuple(tuple,(void *)"João da Silva",0,buf_cont[0]);
    sal=10.23;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)"10.5",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len);
    ///////
    filltuple(tuple,(void *)"Carlos Cavalcanti",0,buf_cont[0]);
    sal=15.67;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)"23.45",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    
    /////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Janete Constantina",0,buf_cont[0]);
    sal=55.3;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)&"23.34",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    //////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Silvia da Silva",0,buf_cont[0]);
    sal=33.33;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)"100.33",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    //////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"João New Page",0,buf_cont[0]);
    sal=36.4;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)"456.78",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    ////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Maria New Page",0,buf_cont[0]);
    sal=51.1;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)"111.11",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    ////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Carl Seagan",0,buf_cont[0]);
    sal=1332.2;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)&"222.22",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    //////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Edgar Codd",0,buf_cont[0]);
    sal=1000.9;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)"333.33",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    ////////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Alan Turing",0,buf_cont[0]);
    sal=4340.4;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)"444.44",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    ///////////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Jonas Jones",0,buf_cont[0]);
    sal=1002.12;
    filltuple(tuple, (void *)&sal,buf_cont[0].len,buf_cont[1]);
    //filltuple(tuple, (void *)"555.55",buf_cont[0].len,buf_cont[1]);
    // copy tuple to buffer pool
    printf("Insert tuple into buffer pool...\n");
    fillbufpool(bufpool,tuple,tup_len); 
    ////
    //printdebug(bufpool);
    ////
    i=0;
    while (bufpool[i].nrec>0)
    {
		printf("Showing page: %d\n",i);
		showBuffer(bufpool,tup_len,buf_cont,i);
		i++;
	}
    free(bufpool);	
    return 1;
}
