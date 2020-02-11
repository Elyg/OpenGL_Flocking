# OpenGL Flocking 
This is my university project, which is an OpenGL application with Qt as the GUI and window manager, showcasing a simple implementation of a flocking system. 
This application is using some libraries created by our lecturer at Bournemouth University (NCCA)
                                                                                                                   
![](https://media.giphy.com/media/S64sNLvefupHxKW1Hf/giphy.gif)

# Library dependancies

 - NGL ([https://github.com/NCCA/NGL](https://github.com/NCCA/NGL))
 - OpenGL
 - Qt5
 - Boost
 - qmake
### How to compile and run the application
```
git clone git@github.com:Elyg/OpenGL_Flocking.git
cd OpenGL_Flocking/
qmake FlockingSystem.pro
make
./FlockingSystem
```

## Based on Craig Reynolds works
### Some of the basic behaviours
*Separation*

![Separation](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e1/Rule_separation.gif/200px-Rule_separation.gif)


*Alignment*

![Alignment](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e1/Rule_alignment.gif/200px-Rule_alignment.gif)

*Cohesion*

![Cohesion](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2b/Rule_cohesion.gif/200px-Rule_cohesion.gif)


# References:
[https://www.red3d.com/cwr/boids/](https://www.red3d.com/cwr/boids/)

[https://en.wikipedia.org/wiki/Boids](https://en.wikipedia.org/wiki/Boids)
