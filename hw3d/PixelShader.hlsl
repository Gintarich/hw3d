struct VSOut
{
	float3 color : Color;
	float4 pos : SV_Position;
};

float4 main(float3 color : Color) : SV_Target
{
	return float4(color,1.0f);
}