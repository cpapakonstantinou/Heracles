#include "oracle.h"
#include "heracles.h"

int oracle::log_level = LOG_INFO;
bool oracle::use_syslog = false;

using namespace oracle;

using E = int; //expected
using U = std::string_view; //unexpected

std::expected<E, U>
nemean_lion(void* instructions)
{
	bool* has_golden_fleece;
	
	if(instructions)
		has_golden_fleece = reinterpret_cast<bool*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*has_golden_fleece)
		return 0;
	else
		return std::unexpected("lion's hide impenetrable to mortal weapons!");
}

std::expected<E, U>
hydra(void* instructions)
{
	int* heads;
	
	if(instructions)
		heads = reinterpret_cast<int*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*heads == 9)
		return 0;
	else
		return std::unexpected("wrong number of heads!");
}

std::expected<E, U>
ceryneian_hind(void* instructions)
{
	int* pursuit_years;
	
	if(instructions)
		pursuit_years = reinterpret_cast<int*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*pursuit_years >= 1)
		return 0;
	else
		return std::unexpected("sacred deer too swift to catch!");
}

std::expected<E, U>
erymanthian_boar(void* instructions)
{
	bool* used_net;
	
	if(instructions)
		used_net = reinterpret_cast<bool*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*used_net)
		return 0;
	else
		return std::unexpected("boar too fierce to capture bare-handed!");
}

std::expected<E, U>
augean_stables(void* instructions)
{
	bool* diverted_rivers;
	
	if(instructions)
		diverted_rivers = reinterpret_cast<bool*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*diverted_rivers)
		return 0;
	else
		return std::unexpected("3000 cattle worth of filth cannot be cleaned in one day!");
}

std::expected<E, U>
stymphalian_birds(void* instructions)
{
	bool* has_bronze_castanets;
	
	if(instructions)
		has_bronze_castanets = reinterpret_cast<bool*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*has_bronze_castanets)
		return 0;
	else
		return std::unexpected("man-eating birds will not emerge from hiding!");
}

std::expected<E, U>
cretan_bull(void* instructions)
{
	bool* subdued_alive;
	
	if(instructions)
		subdued_alive = reinterpret_cast<bool*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*subdued_alive)
		return 0;
	else
		return std::unexpected("mad bull must be captured alive!");
}

std::expected<E, U>
mares_of_diomedes(void* instructions)
{
	bool* fed_diomedes_to_mares;
	
	if(instructions)
		fed_diomedes_to_mares = reinterpret_cast<bool*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*fed_diomedes_to_mares)
		return 0;
	else
		return std::unexpected("man-eating mares cannot be tamed!");
}

std::expected<E, U>
girdle_of_hippolyta(void* instructions)
{
	bool* defeated_amazon_queen;
	
	if(instructions)
		defeated_amazon_queen = reinterpret_cast<bool*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*defeated_amazon_queen)
		return 0;
	else
		return std::unexpected("Amazon queen will not surrender her girdle!");
}

std::expected<E, U>
cattle_of_geryon(void* instructions)
{
	int* heads_of_geryon;
	
	if(instructions)
		heads_of_geryon = reinterpret_cast<int*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*heads_of_geryon == 3)
		return 0;
	else
		return std::unexpected("three-bodied giant guards his cattle!");
}

std::expected<E, U>
apples_of_hesperides(void* instructions)
{
	bool* convinced_atlas;
	
	if(instructions)
		convinced_atlas = reinterpret_cast<bool*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*convinced_atlas)
		return 0;
	else
		return std::unexpected("golden apples are guarded by a dragon!");
}

std::expected<E, U>
cerberus(void* instructions)
{
	int* heads_of_cerberus;
	
	if(instructions)
		heads_of_cerberus = reinterpret_cast<int*>(instructions);
	else
		return std::unexpected("empty instructions");
	
	if (*heads_of_cerberus == 3)
		return 0;
	else
		return std::unexpected("three-headed hound of Hades cannot be captured!");
}

int main(int argc, char const *argv[])
{
	Heracles<E, U> h{};
	
	bool golden_fleece = true;
	h.add_labor(0, "nemean_lion", &nemean_lion, (void*) &golden_fleece);
	
	int hydra_heads = 9;
	h.add_labor(1, "hydra", &hydra, (void*) &hydra_heads);
	
	int pursuit_years = 1;
	h.add_labor(2, "ceryneian_hind", &ceryneian_hind, (void*) &pursuit_years);
	
	bool used_net = true;
	h.add_labor(3, "erymanthian_boar", &erymanthian_boar, (void*) &used_net);
	
	bool diverted_rivers = true;
	h.add_labor(4, "augean_stables", &augean_stables, (void*) &diverted_rivers);
	
	bool has_bronze_castanets = true;
	h.add_labor(5, "stymphalian_birds", &stymphalian_birds, (void*) &has_bronze_castanets);
	
	bool subdued_alive = true;
	h.add_labor(6, "cretan_bull", &cretan_bull, (void*) &subdued_alive);
	
	bool fed_diomedes_to_mares = true;
	h.add_labor(7, "mares_of_diomedes", &mares_of_diomedes, (void*) &fed_diomedes_to_mares);
	
	bool defeated_amazon_queen = true;
	h.add_labor(8, "girdle_of_hippolyta", &girdle_of_hippolyta, (void*) &defeated_amazon_queen);
	
	int heads_of_geryon = 3;
	h.add_labor(9, "cattle_of_geryon", &cattle_of_geryon, (void*) &heads_of_geryon);
	
	bool convinced_atlas = true;
	h.add_labor(10, "apples_of_hesperides", &apples_of_hesperides, (void*) &convinced_atlas);
	
	int heads_of_cerberus = 3;
	h.add_labor(11, "cerberus", &cerberus, (void*) &heads_of_cerberus);
	
	h.perform_labors();
	return 0;
}