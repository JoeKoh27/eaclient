#pragma once
namespace game
{
	struct avs_stat {
		uint64_t st_atime;
		uint64_t st_mtime;
		uint64_t st_ctime;
		uint32_t unk1;
		uint32_t filesize;
		struct stat padding;
	};

	typedef uint32_t avs_file_t;

#define CUR_STYLE_ENTRIES (80 * 1000)
#define MAX_ENTRIES (CUR_STYLE_ENTRIES + 1000)

	namespace BM2D
	{
		struct CColor;
		struct CMask;
		struct CPos;
		struct CLayerBase_vtbl;
		struct CFileData;

		/* 1725 */
		struct CMovieClip
		{
			char m_szTextureName[256];
			int m_movieClipID;
			char m_mcPath[256];
			CFileData* m_pFileData;
		};

		/* 72 */
		enum FilterType : uint32_t
		{
			FILTER_DEFAULT = 0x0,
			FILTER_OFF = 0x80000000,
			FILTER_ON = 0x80000001,
		};

		/* 421 */
		enum ShaderType : uint32_t
		{
			SHADER_DEFAULT = 0x0,
			SHADER_GRAY_SCALE = 0x1,
			SHADER_SEPIA = 0x2,
			SHADER_RASTERSCROLL = 0x3,
			SHADER_ALPHA_BLUR = 0x4,
			SHADER_HSV = 0x5,
		};

		/* 1726 */
		struct ShaderParam
		{
			float m_fValue1;
			float m_fValue2;
			float m_fValue3;
		};

		/* 1727 */
		struct AfpUserParam
		{
			FilterType m_Filter;
			ShaderType m_Shader;
			ShaderParam m_ShaderParam;
		};

		/* 1721 */
		struct CLayerBase
		{
			CLayerBase_vtbl* __vftable /*VFT*/;
			int m_afpLayerID;
			CMovieClip m_rootMC;
			AfpUserParam m_AfpUserParam;
		};

		/* 89 */
		enum PLAYSTATE : __int32
		{
			PLAYSTATE_LOOP = 0x0,
			PLAYSTATE_STOP = 0x1,
			PLAYSTATEMAX = 0x2,
		};

		/* 1729 */
		struct CLayer : CLayerBase
		{
			PLAYSTATE m_playState;
			int m_fileIndex;
		};

		/* 147 */
		enum RENDERSTATE : __int32
		{
			RENDERSTATE_NORMAL = 0x0,
			RENDERSTATE_ADD = 0x1,
			RENDERSTATE_SUBTRACT = 0x2,
			RENDERSTATE_MULTIPLY = 0x3,
			RENDERSTATE_OVERLAY = 0x4,
			RENDERSTATEMAX = 0x5,
		};

		/* 414 */
		enum AnchorType : __int32
		{
			ANCHORTYPE_DEFAULT = 0x0,
			ANCHORTYPE_LEFT = 0x1,
			ANCHORTYPE_RIGHT = 0x2,
			ANCHORTYPE_CENTER = 0x3,
			ANCHORTYPEMAX = 0x4,
			ANCHORTYPE_TOP = 0x1,
			ANCHORTYPE_BOTTOM = 0x2,
		};

		/* 1723 */
		struct /*VFT*/ CLayerBase_vtbl
		{
			void(__thiscall* Init)(CLayerBase* _this);
			void(__thiscall* Destruct)(CLayerBase* _this);
			void(__thiscall* Create)(CLayerBase* _this, int);
			void(__thiscall* Destroy)(CLayerBase* _this);
			void(__thiscall* SetDisp)(CLayerBase* _this, bool);
			void(__thiscall* SetRenderState)(CLayerBase* _this, RENDERSTATE);
			void(__thiscall* SetPos)(CLayerBase* _this, const CPos*);
			void(__thiscall* SetPos_1)(CLayerBase* _this, int, int);
			void(__thiscall* SetRotation)(CLayerBase* _this, float);
			void(__thiscall* SetAnchor)(CLayerBase* _this, AnchorType, AnchorType);
			void(__thiscall* SetAnchor_1)(CLayerBase* _this, float, float);
			void(__thiscall* SetAnchor_2)(CLayerBase* _this, int, int);
			void(__thiscall* SetMask)(CLayerBase* _this, int, int, int, int);
			void(__thiscall* SetMask_1)(CLayerBase* _this, const CMask*);
			void(__thiscall* SetMaskEnable)(CLayerBase* _this, bool);
			void(__thiscall* SetSystemMaskEnable)(CLayerBase* _this, bool);
			void(__thiscall* SetColor)(CLayerBase* _this, float, float, float, float);
			void(__thiscall* SetColor_1)(CLayerBase* _this, const CColor*);
			void(__thiscall* SetAColor)(CLayerBase* _this, float, float, float, float);
			void(__thiscall* SetAColor_1)(CLayerBase* _this, const CColor*);
			void(__thiscall* SetBright)(CLayerBase* _this, int, float, float, float);
			void(__thiscall* SetABright)(CLayerBase* _this, int, float, float, float);
			void(__thiscall* SetScale)(CLayerBase* _this, float, float);
			void(__thiscall* SetScale_1)(CLayerBase* _this, float);
			void(__thiscall* SetScaleLayer)(CLayerBase* _this, float, float);
			void(__thiscall* SetScaleLayer_1)(CLayerBase* _this, float);
			void(__thiscall* SetPriority)(CLayerBase* _this, int);
			void(__thiscall* SetGroup)(CLayerBase* _this, unsigned int);
			void(__thiscall* SetFilter)(CLayerBase* _this, FilterType);
			void(__thiscall* SetShader)(CLayerBase* _this, ShaderType);
			void(__thiscall* SetRasterScroll)(CLayerBase* _this, float, float, float);
			void(__thiscall* SetUserHSVParam)(CLayerBase* _this, float, float, float);
			void(__thiscall* SetUserBlurParam)(CLayerBase* _this, float);
			void(__thiscall* Display)(CLayerBase* _this);
			const char* (__thiscall* GetLayerName)(CLayerBase* _this);
			void(__thiscall* GetSize)(CLayerBase* _this, int*, int*);
			void(__thiscall* GetAnchor)(CLayerBase* _this, float*, float*);
			void(__thiscall* GetAnchor_1)(CLayerBase* _this, int*, int*);
			bool(__thiscall* IsCreated)(CLayerBase* _this);
			bool(__thiscall* GetDisp)(CLayerBase* _this);
			int(__thiscall* GetPriority)(CLayerBase* _this);
		};

		struct CFileData
		{
			enum FileLoadStatus : __int32
			{
				FILE_LOAD_BLANK = 0x0,
				FILE_LOAD_LOADING = 0x1,
				FILE_LOAD_LOADED = 0x2,
				FILE_LOAD_RELEASING = 0x3,
				FILE_LOAD_RELEASED = 0x0,
				FILE_LOAD_STATUS_NUM = 0x1,
			};

			int m_nIndex;
			int m_nCreateLevel;
			char m_szFileName[256];
			char m_szFilePath[256];
			char m_szMountPoint[256];
			bool m_bUseLoadCount;
			int m_loadCount;
			bool m_bUseDestoryLayer;
			FileLoadStatus m_eLoadStatus;
			int m_packageID;
		};

		const struct CPos
		{
			int m_nPosX;
			int m_nPosY;
		};

		struct CMask
		{
			int m_nPosX;
			int m_nPosY;
			int m_nWidth;
			int m_nHeight;
		};

		struct CColor
		{
			float r;
			float g;
			float b;
			float a;
		};
	}

#pragma pack(push, 1)
	struct bpm_t {
		uint32_t min;
		uint32_t max;
	};

	struct music_t {
		char title[0x40];
		char title_ascii[0x40];
		char genre[0x40];
		char artist[0x40];

		uint32_t texture_title;
		uint32_t texture_artist;
		uint32_t texture_genre;
		uint32_t texture_load;
		uint32_t texture_list;

		uint32_t font_idx;
		uint16_t game_version;

		uint16_t other_folder;
		uint16_t bemani_folder;
		uint16_t splittable_diff;

		uint8_t level[10];

		uint8_t __gap1[2];

		bpm_t bpm[10];

		uint8_t __gap2[52];

		uint32_t note_count[10];

		uint8_t __gap3[88];
		uint32_t chart_type[10];
		uint8_t __gap4[24];

		uint32_t song_id;
		uint32_t volume;

		uint8_t ident_sp[5];
		uint8_t ident_dp[5];

		uint16_t bga_delay;

		uint16_t __gap5;

		char bga_filename[0x20];

		uint16_t __gap6;

		uint32_t afp_flag;

		uint8_t afp_data[0x20 * 10];
		uint32_t __gap7;
	};

	static_assert(offsetof(music_t, song_id) == 624);
	static_assert(offsetof(music_t, bga_filename) == 646);
	static_assert(sizeof(music_t) == 0x3F0);

	struct music_data_t {
		uint32_t header;
		uint32_t data_version;
		uint16_t music_count;
		uint16_t zero;
		uint32_t max_entries;
		int16_t index_table[MAX_ENTRIES];
		music_t musics[1];
	};

	struct CMusicSelectScene_s
	{
		char __gap1[328];
		music_t* current_music;
		char __gap2[480];
		int selected_chart;
	};

#pragma pack(pop)
}