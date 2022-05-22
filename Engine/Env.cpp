#include "Env.h"
#include "Graphics.h"

Env::Env() :
	ft()
{
	rng = std::mt19937( std::random_device{}() );
	Start();
}

void Env::spawnBoxes( const int num_boxes )
{
	for (int i = 0; i < num_boxes; i++)
	{
		Env::SpawnBox();
	}
}

void Env::SpawnBox()
{
	std::uniform_int_distribution<int> width_dist( 50, 150 );
	int width = width_dist( rng );
	std::uniform_int_distribution<int> x_dist( width / 2, 800 - (width / 2) );
	std::uniform_int_distribution<int> y_dist( width / 2, 600 - (width / 2) );
	std::uniform_int_distribution<int> color_dist( 0, colors.size() - 1 );
	Color color = colors[color_dist( rng )];

	boxes.emplace_back( x_dist(rng), y_dist(rng), width, 0.0f, color);
}

void Env::Update()
{
	for (Square& s : boxes)
	{
		s.Update();
	}

}

void Env::Draw( Graphics& gfx )
{
	for (Square& s : boxes)
	{
		s.Draw( gfx );
	}
}

void Env::Start()
{
	// sequence
	spawnBoxes( 2 );
	std::uniform_int_distribution<int> force_dist( -70, 70 );
	for (Square& s : boxes)
	{
		s.testLinearMotion( Vec2( force_dist( rng ), force_dist( rng ) ), 1.0f );
	}
}

