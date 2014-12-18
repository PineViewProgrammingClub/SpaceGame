#version 400

layout(location=0) in vec4 in_Position;
out vec4 pass_Color;

void main(void)
{
   gl_Position = in_Position;
   pass_Color = vec4(1,1,1,1);
}