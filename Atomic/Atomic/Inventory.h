#ifndef __ATOMIC__INVENTORY__H
#define __ATOMIC__INVENTORY__H
#include <vector>
#include <functional>
#include "./Item.h"

namespace atomic {
	using ItemContainer = std::vector<atomic::UniqueItem>;
	class Inventory {
	private:
		ItemContainer m_inventory;
	public:
		Inventory() = default;
		Inventory(const ItemContainer& inventory)
			: m_inventory{inventory}
		{
		}

		inline void addItem(const atomic::UniqueItem& item) { this->m_inventory.push_back(item); }
		[[nodiscard]] atomic::UniqueItem& getRandomItem();
		[[nodiscard]] inline const ItemContainer& getInventory() const noexcept { return this->m_inventory; }
		[[nodiscard]] inline const size_t item_count() const noexcept { return this->m_inventory.size(); }
		[[nodiscard]] const ItemContainer::iterator begin() noexcept { return this->m_inventory.begin(); }
		[[nodiscard]] const ItemContainer::iterator end() noexcept { return this->m_inventory.end(); }
		// Searching / Indexing
		[[nodiscard]] atomic::UniqueItem& operator[](int index) { return this->m_inventory[index]; }
		[[nodiscard]] atomic::UniqueItem& findItemByName(const std::string& name);
		[[nodiscard]] atomic::UniqueItem& findItemById(const int& assetId);
		[[nodiscard]] ItemContainer itemMatch(const std::function<bool(const atomic::UniqueItem&)>& function);
	};
}

#endif