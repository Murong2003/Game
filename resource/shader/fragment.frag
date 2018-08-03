#version 330 core
out vec4 temp_color;
in vec2 temp_texcoord_out;

uniform sampler2D temp_texture;

void main() {
   temp_color = texture(temp_texture, temp_texcoord_out);
}
