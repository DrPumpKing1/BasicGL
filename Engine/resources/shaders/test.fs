#version 460 core
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
} fs_in;

void main() {
    FragColor = vec4(fs_in.TexCoords.r, fs_in.TexCoords.g, 1.0, 1.0);
}