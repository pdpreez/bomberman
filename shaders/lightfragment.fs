#version 330 core
out vec4 FragColor;

uniform vec3 LightPos;
uniform vec3 ObjectColor;
uniform vec3 LightColor;

in vec3 Normal;
in vec3 FragPos;

void main()
{
    float ambientStrength = 1.0f;
    vec3 ambientLight = ambientStrength * LightColor;

    vec3 norm = normalize(Normal);
    vec3 LightDir = normalize(LightPos - FragPos);

    float diff = max(dot(norm, LightDir), 0.0f);
    vec3 diffuse = diff * LightColor;

    vec3 result = (ambientLight + diffuse) * ObjectColor;
    FragColor = vec4(result, 1.0);
}