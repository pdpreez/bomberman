#version 330 core
out vec4 FragColor;

uniform vec3 LightPos;
uniform vec3 ObjectColor;
uniform vec3 LightColor;
uniform vec3 ViewPos;

in vec3 Normal;
in vec3 FragPos;

void main()
{
    float ambientStrength = 0.1f;
    vec3 ambientLight = ambientStrength * LightColor;

    vec3 norm = normalize(Normal);
    vec3 LightDir = normalize(LightPos - FragPos);
    float diff = max(dot(norm, LightDir), 0.0f);
    vec3 diffuse = diff * LightColor;

    float specularIntensity = 0.5f;
    vec3 viewDir = normalize(ViewPos - FragPos);
    vec3 reflectDir = reflect(-LightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 100);
    vec3 specular = specularIntensity * spec * LightColor;

    vec3 result = (ambientLight + diffuse + specular) * ObjectColor;
    FragColor = vec4(result, 1.0);
}