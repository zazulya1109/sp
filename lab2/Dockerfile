
FROM debian
RUN apt-get update
RUN apt install gcc gdb gcc-multilib nano -y
COPY lab2.s .
COPY lab2.c .
RUN gcc -m32 -no-pie lab2.s -o lab2
RUN gcc lab2.c -o lab22 
CMD ./lab2 && ./lab22
