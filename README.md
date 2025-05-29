# Fract'ol
## A real-time fractal rendering in C

Fract'ol is a graphical application written in C that allows users to **explore mathematical fractals** such as the Mandelbrot set and various Julia sets in real time. The project uses MiniLibX, a minimal and very low-level graphics library, which required manual implementation of rendering logic.

This project was a great introduction to:

- Basic graphics programming using a **low-level library** (MiniLibX)

- Handling **complex numbers** to generate fractals

- Building an **event-driven interface** (keyboard, mouse)

- Render **without** relying on modern graphical frameworks

Due to the limitations of MiniLibX, there is no built-in support for high-level drawing tools or hardware acceleration, which made the rendering process more manual and educational.

🖱️ Implemented Bonus:
**Zooming is centered** on the mouse cursor position, making exploration more intuitive and interactive as users dive into intricate fractal structures.
<p align="center">
  <img src="https://github.com/imanescence/fract-ol/blob/main/img/screen_project.png" alt="Julia Fractal" width="500"/>
</p>
<p align="center">
<i>Here is an example of Julia's fractal with these two values : 0,285 and 0,01</i>
</p>
