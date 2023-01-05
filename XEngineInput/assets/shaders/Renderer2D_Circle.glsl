//--------------------------
// - Xengine 2D -
// Renderer2D Circle Shader
// --------------------------

#type vertex
#version 330 core

layout(location = 0) in vec3 a_WorldPosition;
layout(location = 1) in vec3 a_LocalPosition;
layout(location = 2) in vec4 a_Color;
layout(location = 3) in float a_Thickness;
layout(location = 4) in float a_Fade;
layout(location = 5) in int a_EntityID;

uniform mat4 u_ViewProjection;

out VertexOutput
{
	vec3 LocalPosition;
	vec4 Color;
	float Thickness;
	float Fade;
	flat int v_EntityID;
}Output;

//layout (location = 0) out VertexOutput Output;
//layout (location = 4) flat out int v_EntityID;

void main()
{
	Output.LocalPosition = a_LocalPosition;
	Output.Color = a_Color;
	Output.Thickness = a_Thickness;
	Output.Fade = a_Fade;

//	LocalPosition = a_LocalPosition;
//	Color = a_Color;
//	Thickness = a_Thickness;
//	Fade = a_Fade;
	Output.v_EntityID = a_EntityID;

	gl_Position = u_ViewProjection * vec4(a_WorldPosition, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 o_Color;
layout(location = 1) out int o_EntityID;

in VertexOutput
{
	vec3 LocalPosition;
	vec4 Color;
	float Thickness;
	float Fade;
	flat int v_EntityID;
}Input;

//layout (location = 0) in VertexOutput Input;
//layout (location = 4) flat in int v_EntityID;

void main()
{
	// Calculate distance and fill circle with white
	float distance = 1.0 - length(Input.LocalPosition);
	float circle = smoothstep(0.0, Input.Fade, distance);
	circle *= smoothstep(Input.Thickness + Input.Fade, Input.Thickness, distance);

	if (circle == 0.0)
		discard;

	// Set output color
	o_Color = Input.Color;
	o_Color.a *= circle;

	o_EntityID = Input.v_EntityID;
//	o_Color = vec4(1.0, 1.0, 0.0, 1.0);
}