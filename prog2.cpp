#include <GL/glut.h>

void display(void) {
    // ウィンドウを塗りつぶす。今回はウィンドウ上にある幾つものバッファのうち、カラーバッファだけを塗りつぶす。
    // (バッファ) -> void
    glClear(GL_COLOR_BUFFER_BIT);
    // glBeginとglEndの間に図形の各頂点の座標値を設定する関数を置く。
    // (描画する図形のタイプ) -> void
    glBegin(GL_POLYGON);
    // 描画する図形の色をdoubleで指定する。今回は頂点毎の指定。図形毎も可能 (r,
    // g, b) -> void
    glColor3d(1.0, 0.0, 0.0);
    // glVertex2にはint float doubleの3種ある
    glVertex2d(-0.9, -0.9);
    glColor3d(0.0, 1.0, 0.0);
    glVertex2d(0.9, -0.9);
    glColor3d(0.0, 0.0, 1.0);
    glVertex2d(0.9, 0.9);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(-0.9, 0.9);
    glEnd();
    // まだ実行されていないOpenGLの命令を全て実行する。
    glFlush();
}

// 一度だけ設定すれば良いものはここに書く
void init(void) {
    // glClear(GL_COLOR_BUFFER_BIT)でウィンドウを塗りつぶす際に使う色を指定する。
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[]) {
    // 初期化。(mainの引数そのまま) -> void
    glutInit(&argc, argv);
    // 表示モードの設定。(モード) -> void
    glutInitDisplayMode(GLUT_RGBA);
    // ウィンドウを開く。(ウィンドウの名前) -> ウィンドウの識別子
    glutCreateWindow(argv[0]);
    // 図形表示。(描画する関数へのポインタ) -> void
    glutDisplayFunc(display);
    init();
    // イベントループを開始する。 -> void
    glutMainLoop();
    return 0;
}
