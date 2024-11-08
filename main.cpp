#include <iostream>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For Sleep()
#include <vector>
#include <ctime>

using namespace std;

// Game dimensions
const int width = 20;
const int height = 20;

// Player coordinates
int playerX = width / 2;
int playerY = height - 1;
int score = 0;

// Bullets and enemies
vector<pair<int, int>> bullets; // Vector of bullets (x, y)
vector<pair<int, int>> enemies; // Vector of enemies (x, y)

bool gameOver;

void setup() {
    gameOver = false;
    score = 0;
    bullets.clear();
    enemies.clear();
    srand(time(0));
}

void draw() {
    system("cls");  // Clear the screen

    // Draw top border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Draw game area
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0) cout << "#";  // Left wall

            if (x == playerX && y == playerY) {
                cout << "^"; // Player
            } else {
                bool isPrinted = false;

                // Draw bullets
                for (auto &bullet : bullets) {
                    if (bullet.first == x && bullet.second == y) {
                        cout << "|";
                        isPrinted = true;
                        break;
                    }
                }

                // Draw enemies
                for (auto &enemy : enemies) {
                    if (enemy.first == x && enemy.second == y) {
                        cout << "E";
                        isPrinted = true;
                        break;
                    }
                }

                if (!isPrinted) cout << " ";
            }

            if (x == width - 1) cout << "#";  // Right wall
        }
        cout << endl;
    }

    // Draw bottom border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                if (playerX > 0) playerX--; // Move left
                break;
            case 'd':
                if (playerX < width - 1) playerX++; // Move right
                break;
            case ' ':
                bullets.push_back({playerX, playerY - 1}); // Fire bullet
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void logic() {
    // Move bullets
    for (auto &bullet : bullets) bullet.second--;

    // Remove bullets that are out of bounds
    bullets.erase(remove_if(bullets.begin(), bullets.end(),
                            [](pair<int, int> b) { return b.second < 0; }),
                  bullets.end());

    // Add new enemy at random position
    if (rand() % 10 < 3) {
        int enemyX = rand() % width;
        enemies.push_back({enemyX, 0});
    }

    // Move enemies down
    for (auto &enemy : enemies) enemy.second++;

    // Check for collisions between bullets and enemies
    for (auto b = bullets.begin(); b != bullets.end();) {
        bool hit = false;
        for (auto e = enemies.begin(); e != enemies.end();) {
            if (b->first == e->first && b->second == e->second) {
                score += 10;
                e = enemies.erase(e); // Remove enemy
                hit = true;
                break;
            } else {
                ++e;
            }
        }
        if (hit) {
            b = bullets.erase(b); // Remove bullet
        } else {
            ++b;
        }
    }

    // Check if any enemy reached the player
    for (auto &enemy : enemies) {
        if (enemy.second == playerY && enemy.first == playerX) {
            gameOver = true;
            cout << "Game Over! Final Score: " << score << endl;
            break;
        }
    }

    // Remove enemies that go out of bounds
    enemies.erase(remove_if(enemies.begin(), enemies.end(),
                            [](pair<int, int> e) { return e.second >= height; }),
                  enemies.end());
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // Control game speed
    }
    return 0;
}
