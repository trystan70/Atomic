#ifndef __ATOMIC__ROBLOX__WRAPPER__H
#define __ATOMIC__ROBLOX__WRAPPER__H
#include <string>
#include "./Rolimons.h"
#include "../User.h"
#include "../Inventory.h"
#include "../Offer.h"
#include "../AuthUser.h"
#include "../Trade.h"

/*
* Wrapper for the Roblox API
*/

namespace roblox {
	enum class Membership {
		Normal,
		Premium
	};

	enum class TradeResult {
		Success,
		Failure
	};

	[[nodiscard]] std::string getToken(const std::string& cookie);
	[[nodiscard]] atomic::AuthUser getUserFromCookie(std::string cookie);
	[[nodiscard]] roblox::Membership getMembership(atomic::AuthUser authuser, atomic::User user);
	[[nodiscard]] atomic::Inventory getInventory(atomic::User user, rolimons::ItemDB& items);
	roblox::TradeResult sendTrade(atomic::AuthUser user, atomic::Trade trade);
	roblox::TradeResult counterTrade(atomic::AuthUser user, const atomic::Trade& trade, const atomic::Offer& newOffer);
	roblox::TradeResult declineTrade(atomic::AuthUser user, const atomic::Trade& trade);
	[[nodiscard]] bool can_trade(atomic::AuthUser user, atomic::User target);
	[[nodiscard]] atomic::Trade getTrade(atomic::AuthUser& user, rolimons::ItemDB& items, int tradeId);
	[[nodiscard]] std::vector<atomic::User> getResellers(atomic::AuthUser user, atomic::Item item);
	[[nodiscard]] std::vector<atomic::User>& getUsersInGroup(int groupId, std::int64_t roleId);
	[[nodiscard]] std::vector<atomic::Trade> getTrades(atomic::AuthUser user, atomic::TradeType tradeType, int limit=25);
}

#endif