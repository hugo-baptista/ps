#include <fcntl.h>

#define MAX 4096

int main() {
        char c[MAX];
        int n;

        int d[2];

        pipe(d);
        if(!fork()){
                while( (n=read(0,c,MAX)) > 0 )
                        write (d[1],c,n);
                return(0);
        }

        while( (n=read(d[0],c,MAX)) > 0 )
                write (1,c,n);
        return(0);
}
