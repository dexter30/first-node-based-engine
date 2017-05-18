#version 400 
				 in vec2 ex_UV; 
				 in vec4 ex_Color; 
				 in vec3 ex_Norm; 
				 uniform sampler2D myText; 
				 out vec4 out_Color; 

				 void main(void) 
				 { 
				  out_Color = ex_Color; 
				 vec3 l = normalize(vec3(-1.0, -1.0, -1.0));  
				  float d = dot(l, ex_Norm);	 
				  out_Color = texture(myText, ex_UV); 
				  //out_Color = vec4(1.0, 1.0, 0.0,1.0) * ex_UV.y; 
				 }