#version 400 

layout(location=0) in vec3 in_Position; 
layout(location=1) in vec3 in_norm; 
layout(location=2) in vec2 in_UV; 
out vec4 ex_Color; 
out vec3 ex_Norm; 
out vec2 ex_UV; 
uniform mat4 projMat;  
uniform mat4 in_Model;  
uniform mat4 in_View;  
uniform vec4 WSlight; 
void main(void) 
{ 
 gl_Position =  projMat *  in_View * in_Model* vec4(in_Position,1.0)  ; 
 ex_Color = vec4(in_norm.x, in_norm.y, in_norm.z, 1.0); 
 ex_Norm = in_norm; 
 ex_UV = in_UV; 
}