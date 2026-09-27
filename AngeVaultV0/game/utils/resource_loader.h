#pragma once

struct IResourceLoader {
	virtual ~IResourceLoader() = default;
	virtual void LoadResource(const std::string& id) = 0;
	// virtual void loadTextureAsync(const std::string& id, std::function<void(sf::Texture*)> callback) {}
	// — le jour où le besoin est confirmé,
	//     seule l'implémentation change, aucun appelant à toucher
	virtual void UnloadResource(const std::string& id) = 0;
};