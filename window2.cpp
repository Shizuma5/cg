#include <GL/glut.h>

void display(void)
{
  //ウィンドウを塗りつぶします. mask には塗りつぶすバッファを指定します.
  //OpenGL が管理する画面上のバッファ (メモリ) には, 色を格納するカラーバッファの他,
  //隠面消去処理に使うデプスバッファ, 凝ったことをするときに使うステンシルバッファ,
  //カラーバッファの上に重ねて表示されるオーバーレイバッファなど, いくつかのものがあり,
  //これらが一つのウィンドウに重なって存在しています. mask に GL_COLOR_BUFFER_BIT を指定したときは, カラーバッファだけが塗りつぶされます.
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3d(1.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
  glVertex2d(-0.9, -0.9);
  glVertex2d(0.9, -0.9);
  glVertex2d(0.9, 0.9);
  glVertex2d(-0.9, 0.9);
  glEnd();

  //glFlush() はまだ実行されていない OpenGL の命令を全部実行します.
  //OpenGL は関数呼び出しによって生成される OpenGL の命令をその都度実行するのではなく, いくつか溜め込んでおいてまとめて実行します.
  //このため, ある程度命令が溜まらないと 関数を呼び出しても実行が開始されない場合があります.
  //glFlush() はそういう状況で まだ実行されていない残りの命令の実行を開始します.
  //ひんぱんに glFlush() を呼び出すと, かえって描画速度が低下します.
  glFlush();
}

void init(void)
{
  //glClear(GL_COLOR_BUFFER_BIT) でウィンドウを塗りつぶす際の色を指定します.
  //R，G，B はそれぞれ赤, 緑, 青色の成分の強さを示す GLclampf 型 (float 型と等価) の値で, 0〜1 の間の値を持ちます.
  //1 が最も明るく, この三つに (0, 0, 0) を指定すれば黒色, (1, 1, 1) を指定すれば白色になります.
  //上の例ではウィンドウは青色で塗りつぶされます.
  //最後の A はα値と呼ばれ, OpenGL では不透明度として扱われます (0 で透明, 1 で不透明). ここではとりあえず 1 にしておいてください.
  glClearColor(0.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);

  //ディスプレイの表示モードを設定します. mode に GLUT_RGBA を指定した場合は, 色の指定を RGB (赤緑青, 光の三原色) で行えるようにします.
  //他にインデックスカラーモード (GLUT_INDEX) も指定できます.
  //後者はうまく使えば効率の良い表示が行えますが, それなりに面倒なので, ここではお任せで使える RGBA モードを使います.
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}
