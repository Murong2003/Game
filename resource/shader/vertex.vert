#version 330 core
layout (location = 0) in vec3 temp_pos;
layout (location = 1) in vec2 temp_texcoord_in;

out vec2 temp_texcoord_out;
uniform mat4 temp_model;
uniform mat4 temp_view;
uniform mat4 temp_projection;

void main() {
    gl_Position = temp_projection * temp_view * temp_model * vec4(temp_pos / 200.0, 1.0);
    temp_texcoord_out = vec2(temp_texcoord_in.x, temp_texcoord_in.y);
}
