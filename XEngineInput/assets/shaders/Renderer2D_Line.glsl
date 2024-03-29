//--------------------------
// - Xengine 2D -
// Renderer2D Line Shader
// --------------------------

#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in int a_EntityID;

uniform mat4 u_ViewProjection;


out VertexOutput
{
	vec4 Color;
	flat int v_EntityID;
}Output;

//layout (location = 0) out VertexOutput Output;
//layout (location = 1) out flat int v_EntityID;

void main()
{
	Output.Color = a_Color;
	Output.v_EntityID = a_EntityID;

	gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 o_Color;
layout(location = 1) out int o_EntityID;

in VertexOutput
{
	vec4 Color;
	flat int v_EntityID;
}Input;

//layout (location = 0) in VertexOutput Input;
//layout (location = 1) in flat int v_EntityID;

void main()
{
	o_Color = Input.Color;
	o_EntityID = Input.v_EntityID;
}