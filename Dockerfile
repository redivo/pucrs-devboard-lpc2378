FROM debian:bullseye

# Install required packets
RUN apt-get update
RUN apt-get install gcc -y
RUN apt-get install g++ -y
RUN apt-get install gcc-arm-none-eabi -y
RUN apt-get install cmake -y
