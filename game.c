#include "headers.h"
#include "fncs.h"

char *enemy_ip;

#define BORDER 0x5A2BE2
int fi[4],si[4],sum1,sum2;
int res1 = 0;
int res2 = 0;
int i = 0;
size_t fb_size, map_size, page_size;
int fb;
struct fb_var_screeninfo info;
uint32_t *ptr;
pthread_t thread,thread2,thread_key1,thread_key2,thread_send,thread_recv,thread_press;
pthread_mutex_t mutex;
int ch1='0';
int ch2='0';
int ch_dead='0';
int way = 0;
int way2 = 0;
struct sockaddr_in me, other;
int my_fd = 0;
int other_fd = 0;
int size = sizeof(me);

typedef struct Bike{
   int flag_of_die;
  unsigned int x;
  unsigned int y;
  unsigned int key;
  unsigned int side;
  int name;
  int head[5];
  uint32_t color;
  uint32_t enemy_color;
  uint32_t heade;
}Bike;

char host[NI_MAXHOST];



int main(int argc, char *argv[]){
    pthread_mutex_init(&mutex, NULL);

    int args[2];
    if(argc < 4){
      printf("Usage: %s Xres Yres Enemy_ip\n",argv[0]);
      exit(0);
    }
    args[0] = atoi(argv[1]);
    args[1] = atoi(argv[2]);

      enemy_ip = argv[3];
	get_local_ip();
  sscanf(host,"%d.%d.%d.%d",&fi[0],&fi[1],&fi[2],&fi[3]);
   sscanf(argv[3],"%d.%d.%d.%d",&si[0],&si[1],&si[2],&si[3]);
   sum1 = fi[0]+fi[1]+fi[2]+fi[3];
     sum2 = si[0]+si[1]+si[2]+si[3];
    initialization(args,argv);

      other.sin_family = AF_INET;
      other.sin_addr.s_addr = inet_addr((argv[3]));
      other.sin_port = htons(12345);
       if ( (other_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
          perror("socket creation failed");
          munmap(ptr, map_size);
          endwin();
          exit(EXIT_FAILURE);
      }

      me.sin_family    = AF_INET;
      me.sin_addr.s_addr = inet_addr(host);
      me.sin_port = htons(12345);

      if ( (my_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
          perror("socket creation failed");
          munmap(ptr, map_size);
          endwin();
          exit(EXIT_FAILURE);
      }
      if ( bind(my_fd, (const struct sockaddr *)&me,sizeof(me)) < 0 )
      {
          perror("bind failed");
          munmap(ptr, map_size);
          endwin();
          exit(EXIT_FAILURE);
      }

    pthread_t thread_key1,thread_key2,thread_cikla;;

	struct sockaddr_in a;
	char lub = '0';
	int bs = 0;
	sendto(my_fd,&lub,1,0,(struct sockaddr*)&other,sizeof(other));
	recvfrom(my_fd,&lub,1,0,(struct sockaddr*)&a,&bs);


   // pthread_create(&thread_cikla,NULL,init_bikes_and_cikl,NULL);
	init_bikes_and_cikl();

  //  pthread_join(thread_cikla,NULL);
    munmap(ptr, map_size);
    close(fb);
    endwin();
    return 0;
}
