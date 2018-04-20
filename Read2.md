## SHADERS STEP by STEP
<a href="http://docs.gl/"><b>OPEN GL documentation</b><a><br>
<a href="https://www.khronos.org/opengles/sdk/docs/reference_cards/OpenGL-ES-2_0-Reference-card.pdf"><b>ES 2.0</b><a><br>
1. Сначала создаем шейдер вершин, возвращает ненулевое значение, дескриптор:<br>
<a href="http://docs.gl/es2/glCreateShader"><b>glCreateShader</b><a><br>
```
GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
```
2. Создаем строку, в котором прописываем текст шейдера:<br>
  <b>attribute</b> - спецификатор<br>
  переменные могут быть объявлены предварительно в хранилище спецификатора<br>
  Связь между вершинным шейдером и OpenGL ES для первичных данных по вершинам<br>
  <b>vec2</b> - 2 вектора типа float<br>
  <b>gl_Position</b> - Outputs: специальная переменная для вертексного шейдера<br>
	трансформированные вершины <br>
```
const GLchar* vertex_shader_src = R"(
attribute vec2 a_position;
void main()
{
	gl_Position = vec4(a_position, 0.f, 1.f);
})";
	
```  
3. Заменяем исходный код в шейдерном объекте:<br>
<a href="http://docs.gl/es2/glShaderSource"><b>glShaderSource</b><a><br>
```
glShaderSource(vert_shader, 1, &vertex_shader_src, NULL);
	
```  
3. Заменяем исходный код в шейдерном объекте:<br>
<a href="http://docs.gl/es2/glShaderSource"><b>glShaderSource</b><a><br>
```
glShaderSource(vert_shader, 1, &vertex_shader_src, NULL);
	
```  

