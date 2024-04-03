#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BP 128
#define SIZE 1024

struct buffer {
   unsigned char db;
   unsigned char pc;
   unsigned char nrec;
   unsigned char nbyt;
   char data[SIZE];
};

union c_double
{
	double dbl;
	char   cdbl[sizeof(double)];
};

union c_int
{
	int  num;
	char cnum[sizeof(int)];
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

void filltuple(char *tp, const void *v, char t, int st)
{
	char  *str=(char *)v;
	int *i=(int *)v;
	double *f=(double *)v;
	union c_double cd;
	union c_int ci;
	printf("Inserting into the buffer pool: ");
	ci.num=*i;
	cd.dbl=*f;
	switch (t)
	{
	  case 'S': cpystr(tp,str,st,30);
	            printf("%s\n",tp);
	            break;
	  case 'I': cpystr(tp,ci.cnum,st,4);
	            break;
	  case 'D': cpystr(tp,cd.cdbl,st,8);
	            printf("%f\n",cd.dbl);
	            break;
	  case 'F': break;
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

void showBuffer(struct buffer *bp, int p)
{
    int i=0;
    int limit;
    int st=0;
    if (p<0 || p>=BP)
    { 
		printf("Invalid page number!\n");
		return;
	}
	limit=bp[p].nrec*bp[p].nbyt;
    char found0=0;
	while (i<limit)
	{
	   if (st < 38)
	   {
	      if (st < 30)
	      {
			 if (bp[p].data[i]==0) found0=1;
             if (!found0)
	            printf("%c",bp[p].data[i]);
	         else printf(" ");
	      }
	      else
	      {
			  double *n=(double *)&bp[p].data[i];
			  printf(" %f \n",*n);
			  i+=7;
			  st=-1;
			  found0=0;
	      }
	      st++;
	   }
	   else st=0;  
	   i++;
	}      
	printf("\n");
	return;
}

int main()
{
	char *tuple=(char *)malloc(sizeof(char)*34); //tuple's length
	struct buffer *bufpool;
	double sal;
	//int   i;
	printf("Starting buffer manager (%d pages)...\n",BP);
	bufpool=(struct buffer *)malloc(sizeof(struct buffer)*BP);
	if (bufpool==NULL)
	{
		printf("Out of memory for buffer pool!\n");
		return 0;
    }
    initbuffer(bufpool); 
    //// fill buffer pool 
    //// each tuple has 38 bytes: 30 bytes for name and 8 bytes for salary
    //
    // fill tuple with a tuple
    //        tuple    value    type start
    //          |        |        |  |
    filltuple(tuple,(void *)"João da Silva",'S',0);
    sal=10.23;
    filltuple(tuple, (void *)&sal,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38);
    

    filltuple(tuple,(void *)"Carlos Cavalcanti",'S',0);
    sal=15.67;
    filltuple(tuple, (void *)&sal,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    
    /////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Janete Constantina",'S',0);
    sal=55.3;
    filltuple(tuple, (void *)&sal,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    //////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Silvia da Silva",'S',0);
    sal=33.33;
    filltuple(tuple, (void *)&sal,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    //////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"João New Page",'S',0);
    sal=36.4;
    filltuple(tuple, (void *)&sal,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    ////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Maria New Page",'S',0);
    sal=51.1;
    filltuple(tuple, (void *)&sal,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    /*
    ////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Pessoa 6",'S',0);
    age=32.2;
    filltuple(tuple, (void *)&age,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    //////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Pessoa 7",'S',0);
    age=29.9;
    filltuple(tuple, (void *)&age,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    ////////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Pessoa 8",'S',0);
    age=40.4;
    filltuple(tuple, (void *)&age,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    ///////////////////////////////////
    // fill tuple with a tuple
    filltuple(tuple,(void *)"Pessoa 9",'S',0);
    age=12.12;
    filltuple(tuple, (void *)&age,'D',30);
    // copy tuple to buffer pool
    fillbufpool(bufpool,tuple,38); 
    ////
    */
    //printdebug(bufpool);
    ////
    showBuffer(bufpool,0);
    free(bufpool);	
    return 1;
}
