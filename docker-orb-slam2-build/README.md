# Docker ORB_SLAM2 Build

Build [ORB_SLAM2](https://github.com/raulmur/ORB_SLAM2) in a Docker container starting from Ubuntu 16.04.

## To build manually

```
$ docker build -t lucas/docker-orb-slam2-build .
```

## To run
This assumes that you are in the directory `~/docker/` with the ORB_SLAM2 repository cloned inside of this repository.
The Docker image will mount `~/docker/ORB_SLAM2` on your local machine to `/ORB_SLAM2` so that the compiled files can be retrieved there after the container is killed.
Run the following on the command line:
```
$ docker run -v ~/docker/ORB_SLAM2/:/ORB_SLAM2/ -w=/ORB_SLAM2/ lucas/docker-orb-slam2-build /bin/bash -c ./build.sh
```
This will run the build script from ORB_SLAM2 in the container.