# GesturalInterfaces
Gestural Interfaces
This project is an experiment with developing a wireless gestural interaction with virtual object actualized as holograms.

I've used Unity for the hologram of earth referenced and customized from here: https://assetstore.unity.com/packages/tools/hologram-pyramid-61735

I used this tutorial here to code the connection between Arduino and Unity: https://www.alanzucconi.com/2015/10/07/how-to-integrate-arduino-with-unity/. There were some issues with the readings initially, and the changed code is in my repository here.

The sensor data is being mapped to the rotation of the object in Unity. I have also experimented with adding x, y, and z axis linear trasnforms with rotational aspects, but it mapping both rotational and linear transforms based off flex sensor's data made the object glitch and unstable. It also slowed Unity down for some reason. The core here only maps rotational transformation for now. 
