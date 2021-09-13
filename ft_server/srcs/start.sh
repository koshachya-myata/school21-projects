docker build -t serv ../
docker run -it --rm -p 80:80 -p 443:443 serv

#docker build -t serv . 
#docker run --rm --name serv -d -p 80:80 -p 443:443 serv
#docker exec -it serv bash
