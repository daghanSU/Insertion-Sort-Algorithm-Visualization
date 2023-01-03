#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int ekle = arr[j + 1];

		while (j >= 0 && ekle < arr[j]) {
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;

			j--;
		}

		arr[j + 1] = ekle;
	}
}

int main() {
	const int width = 1200;
	Vector2i window_size = Vector2i(width, 800);
	RenderWindow* window = new RenderWindow(VideoMode(window_size.x,window_size.y), "Insertion Sort");
	window->setFramerateLimit(60);

	srand(time(0));

	// Init heights

	int heights[width];
	for (int i = 0; i < width; i++) {
		heights[i] = rand() % window_size.y + 1;
	}

	int i = 1;
	int j = i - 1;
	
	while (window->isOpen()) {
		Event event;
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}
		}
		// Sort
		if (i < width) {
			int ekle = heights[j + 1];

			if (ekle >= heights[j]) {
				heights[j + 1] = ekle;
				i++;
				j = i - 1;
			}
			else if (j >= 0 && ekle < heights[j]) {
				int temp = heights[j];
				heights[j] = heights[j + 1];
				heights[j + 1] = temp;

				j--;

				if (j < 0) {
					i += 1;
					j = i - 1;
				}
			}
		}

		

		window->clear(Color::Black);
		// Draw
		for (int i = 0; i < width; i++) {
			RectangleShape t_rect(Vector2f(1, heights[i]));
			t_rect.setFillColor(Color::Green);
			t_rect.setPosition(i, window_size.y - heights[i]);
			window->draw(t_rect);
		}
		window->display();
	}
}