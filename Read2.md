## SHADERS STEP by STEP
<a href="http://docs.gl/"><b>OPEN GL documentation</b><a><br>
1. Сначала создаем шейдер вершин, возвращает ненулевое значение, дескриптор:<br>
<a href="http://docs.gl/es2/glCreateShader"><b>glCreateShader</b><a><br>
```
GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
```
2. Создаем строку, в котором прописываем текст шейдера:<br>
  attribute - спецификатор<br>
  переменные могут быть объявлены предварительно в хранилище спецификатора<br>
  Связь между вершинным шейдером и OpenGL ES для первичных данных по вершинам<br>
  vec2 
<a href="http://docs.gl/es2/glCreateShader"><b>glCreateShader</b><a><br>
```
const GLchar* vertex_shader_src = R"(
attribute vec2 a_position;
void main()
{
	gl_Position = vec4(a_position, 0.f, 1.f);
})";
```  

