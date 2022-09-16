#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include <filesystem>

constexpr auto plugin_version = "1.0-yak";

enum class ProductQuality : uint8_t
{
	Common = 0,
	Uncommon = 1,
	Rare = 2,
	VeryRare = 3,
	Import = 4,
	Exotic = 5,
	BlackMarket = 6,
	Premium = 7,
	Limited = 8,
	Legacy = 9,
	MAX = 10
};

struct ProductQualityInfo
{
	std::string name;
};

struct ProductStruct
{
	int product_id = 0;
	std::string name;
	std::string slot;
	std::string paint = "none";
	std::string certification = "none";
	int certification_value = 0;
	std::string rank_label = "none";
	std::string special_edition = "none";
	std::string quality = "unknown";
	std::string crate;
    int series_id = 0;
	std::string series;
	unsigned long long instance_id = 0;
	bool tradeable = false;

	int blueprint_item_id = 0;
	std::string blueprint_item;
	int blueprint_cost = 0;

	int amount = 1;
};

class BetterInventoryExport: public BakkesMod::Plugin::BakkesModPlugin/*, public BakkesMod::Plugin::PluginWindow*/
{
	using HandleAttribute = std::function<void(ProductAttributeWrapper paw, ProductStruct& productData)>;
private:
	std::map<std::string, HandleAttribute> attributeHandler;
	const std::map<uint8_t, ProductQualityInfo> productQualities = {
		{(uint8_t)ProductQuality::Common, {"Common"}},
		{(uint8_t)ProductQuality::Uncommon, {"Uncommon"}},
		{(uint8_t)ProductQuality::Rare, {"Rare"}},
		{(uint8_t)ProductQuality::VeryRare, {"Very rare"}},
		{(uint8_t)ProductQuality::Import, {"Import"}},
		{(uint8_t)ProductQuality::Exotic, {"Exotic"}},
		{(uint8_t)ProductQuality::BlackMarket, {"Black market"}},
		{(uint8_t)ProductQuality::Premium, {"Premium"}},
		{(uint8_t)ProductQuality::Limited, {"Limited"}},
		{(uint8_t)ProductQuality::Legacy, {"Legacy"}},
	};
	
	//Make sure the index of the name in this vector matches the paintID
	const std::vector<std::string> paintNames = {
		"None",
		"Crimson",
		"Lime",
		"Black",
		"Sky Blue",
		"Cobalt",
		"Burnt Sienna",
		"Forest Green",
		"Purple",
		"Pink",
		"Orange",
		"Grey",
		"Titanium White",
		"Saffron",
		"Gold",
		"Rose Gold",
		"White Gold",
		"Onyx",
		"Platinum"
	};
public:
	virtual void onLoad();
	virtual void onUnload();

	void OnInventDump(std::vector<std::string> params);

	ProductStruct GetProductInfo(ProductWrapper& pw);

	ProductStruct GetOnlineProductInfo(OnlineProductWrapper& pw);


	void export_csv(const std::filesystem::path& filename, std::vector<ProductStruct>& psv);
	void export_json(const std::filesystem::path& filename, std::vector<ProductStruct>& psv);
};

