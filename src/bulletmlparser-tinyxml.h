/// BulletML �̃p�[�T�E�c���[ by tinyxml
/**
 * tinyxml�ɂ��BulletML�̃p�[�T
 */

#ifndef BULLETMLPARSER_TINYXML_H_
#define BULLETMLPARSER_TINYXML_H_

#include <string>

#include "bulletmlcommon.h"
#include "bulletmlparser.h"

#if defined(__PSP__) || defined(__PS2__)
#include "tinyxml.h"
#else
#include "tinyxml/tinyxml.h"
#endif

class BulletMLNode;

class BulletMLParserTinyXML : public BulletMLParser {
public:
    DECLSPEC BulletMLParserTinyXML(const std::string& filename);
    DECLSPEC virtual ~BulletMLParserTinyXML();

    DECLSPEC virtual void parse();

protected:
	void parseImpl(TiXmlDocument& doc);

protected:
    void getTree(TiXmlNode* node);
    void translateNode(TiXmlNode* node);

private:
    std::string xmlFile_;
    BulletMLNode* curNode_;
};

#endif // ! BULLETMLPARSER_TINYXML_H_
