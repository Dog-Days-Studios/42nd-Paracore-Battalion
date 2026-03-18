class XtdGearModels
{
    class CfgWeapons
    {
        class Para42_Helmets
        {
            label = "[42nd] Helmets";
            author = "HoundaCivic";
            options[] = {"helmet"};

            class helmet
            {
                label = "Helmet";
                values[] =
                {
                    "h_ct_p2",
                    "h_cpltl_p2",
                    "h_csgt_p2",
                    "h_cst_p2",
                    "h_medic_p2",
                    "h_cvt_medic_p2",
                    "h_squad_medic_p2",
                    "h_cvt_p2",
                    "h_nco_p2",
                    "h_eod_p2",
                    "h_eod_vet",
                    "h_arf",
                    "h_pilot_trainee",
                    "h_pilot_wo1",
                    "h_pilot_wo2",
                    "h_pilot_wo3",
                    "h_rose",
                    "h_hound",
                    "h_walker"
                };
                class h_ct_p2 { label = "P2"; };
                class h_cpltl_p2 { label = "Platoon Lead P2"; };
                class h_csgt_p2 { label = "Squad Lead P2"; };
                class h_cst_p2 { label = "Senior Trooper P2"; };
                class h_medic_p2 { label = "Medic P2"; };
                class h_cvt_medic_p2 { label = "CVT Medic P2"; };
                class h_squad_medic_p2 { label = "Squad Medic P2"; };
                class h_cvt_p2 { label = "CVT P2"; };
                class h_nco_p2 { label = "NCO P2"; };
                class h_eod_p2 { label = "EOD P2"; };
                class h_eod_vet { label = "EOD Veteran"; };
                class h_arf { label = "ARF"; };
                class h_pilot_trainee { label = "Pilot Trainee"; };
                class h_pilot_wo1 { label = "Pilot WO1"; };
                class h_pilot_wo2 { label = "Pilot WO2"; };
                class h_pilot_wo3 { label = "Pilot WO3"; };
                class h_rose { label = "Rose"; };
                class h_hound { label = "Hound"; };
                class h_walker { label = "Walker"; };
            };
        };

        class Para42_Uniforms
        {
            label = "[42nd] Uniforms";
            author = "HoundaCivic";
            options[] = {"uniform"};

            class uniform
            {
                label = "Uniform";
                values[] =
                {
                    "u_basic",
                    "u_cpltl",
                    "u_csgt",
                    "u_cst",
                    "u_medic",
                    "u_cvt_medic",
                    "u_squad_medic",
                    "u_cvt",
                    "u_nco",
                    "u_eod",
                    "u_eod_vet",
                    "u_rose",
                    "u_hound",
                    "u_walker"
                };
                class u_basic { label = "Basic"; };
                class u_cpltl { label = "Platoon Lead"; };
                class u_csgt { label = "Squad Lead"; };
                class u_cst { label = "CST"; };
                class u_medic { label = "Medic"; };
                class u_cvt_medic { label = "CVT Medic"; };
                class u_squad_medic { label = "Squad Medic"; };
                class u_cvt { label = "CVT"; };
                class u_nco { label = "NCO"; };
                class u_eod { label = "EOD"; };
                class u_eod_vet { label = "EOD Veteran"; };
                class u_rose { label = "Rose"; };
                class u_hound { label = "Hound"; };
                class u_walker { label = "Walker"; };
            };
        };

        class Para42_Weapons
        {
            label = "[42nd] Weapons";
            author = "HoundaCivic";
            options[] = {"weapon", "tag"};

            class weapon
            {
                label = "Weapon";
                values[] =
                {
                    "w_773firepuncher",
                    "w_774cx",
                    "w_dc15a",
                    "w_dc15a_gl",
                    "w_dc15a_gl_plastic",
                    "w_dc15a_plastic",
                    "w_dc15a_wooden",
                    "w_dc15ac",
                    "w_dc15br",
                    "w_dc15br_wooden",
                    "w_dc15c",
                    "w_dc15c_gl",
                    "w_dc15le",
                    "w_dc15p",
                    "w_dc15s",
                    "w_dc15s_gl",
                    "w_dc15sa",
                    "w_dc15x",
                    "w_dc17",
                    "w_dc17s",
                    "w_dc17s_dual",
                    "w_dlt15",
                    "w_dlt19",
                    "w_dlt19d",
                    "w_dp23_gl",
                    "w_dw32s",
                    "w_fa11",
                    "w_firepuncher",
                    "w_fusioncutter",
                    "w_galaar90",
                    "w_iqa11",
                    "w_rps6",
                    "w_valken38x",
                    "w_z6"
                };
                class w_773firepuncher { label = "773FIREPUNCHER"; };
                class w_774cx { label = "774CX"; };
                class w_dc15a { label = "DC15A"; };
                class w_dc15a_gl { label = "DC15A GL"; };
                class w_dc15a_gl_plastic { label = "DC15A GL PLASTIC"; };
                class w_dc15a_plastic { label = "DC15A PLASTIC"; };
                class w_dc15a_wooden { label = "DC15A WOODEN"; };
                class w_dc15ac { label = "DC15AC"; };
                class w_dc15br { label = "DC15BR"; };
                class w_dc15br_wooden { label = "DC15BR WOODEN"; };
                class w_dc15c { label = "DC15C"; };
                class w_dc15c_gl { label = "DC15C GL"; };
                class w_dc15le { label = "DC15LE"; };
                class w_dc15p { label = "DC15P"; };
                class w_dc15s { label = "DC15S"; };
                class w_dc15s_gl { label = "DC15S GL"; };
                class w_dc15sa { label = "DC15SA"; };
                class w_dc15x { label = "DC15X"; };
                class w_dc17 { label = "DC17"; };
                class w_dc17s { label = "DC17S"; };
                class w_dc17s_dual { label = "DC17S DUAL"; };
                class w_dlt15 { label = "DLT15"; };
                class w_dlt19 { label = "DLT19"; };
                class w_dlt19d { label = "DLT19D"; };
                class w_dp23_gl { label = "DP23 GL"; };
                class w_dw32s { label = "DW32S"; };
                class w_fa11 { label = "FA11"; };
                class w_firepuncher { label = "FIREPUNCHER"; };
                class w_fusioncutter { label = "FUSIONCUTTER"; };
                class w_galaar90 { label = "GALAAR90"; };
                class w_iqa11 { label = "IQA11"; };
                class w_rps6 { label = "RPS6"; };
                class w_valken38x { label = "VALKEN38X"; };
                class w_z6 { label = "Z6"; };
            };

            class tag
            {
                label = "Source";
                values[] = {"as3", "jlts", "ls", "ida"};
                class as3 { label = "3AS"; };
                class jlts { label = "JLTS"; };
                class ls { label = "LS"; };
                class ida { label = "IDA"; };
            };
        };
    };
};

class XtdGearInfos
{
    class CfgWeapons
    {
        class 42nd_CT_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_ct_p2";
        };
        class 42nd_CPLTL_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_cpltl_p2";
        };
        class 42nd_CSGT_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_csgt_p2";
        };
        class 42nd_CST_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_cst_p2";
        };
        class 42nd_Medic_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_medic_p2";
        };
        class 42nd_CVT_Medic_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_cvt_medic_p2";
        };
        class 42nd_Squad_Medic_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_squad_medic_p2";
        };
        class 42nd_CVT_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_cvt_p2";
        };
        class 42nd_NCO_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_nco_p2";
        };
        class 42nd_EOD_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_eod_p2";
        };
        class 42nd_EOD_Vet_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_eod_vet";
        };
        class 42nd_ARF_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_arf";
        };
        class 42nd_Trainee_Pilot_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_pilot_trainee";
        };
        class 42nd_WO1_Pilot_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_pilot_wo1";
        };
        class 42nd_WO2_Pilot_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_pilot_wo2";
        };
        class 42nd_WO3_Pilot_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_pilot_wo3";
        };
        class 42nd_Rose_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_rose";
        };
        class 42nd_Hound_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_hound";
        };
        class 42nd_Walker_P2_Helmet
        {
            model = "Para42_Helmets";
            helmet = "h_walker";
        };

        class 42nd_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_basic";
        };
        class 42nd_CPLTL_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_cpltl";
        };
        class 42nd_CSGT_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_csgt";
        };
        class 42nd_CST_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_cst";
        };
        class 42nd_medic_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_medic";
        };
        class 42nd_CVT_Medic_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_cvt_medic";
        };
        class 42nd_Squad_Medic_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_squad_medic";
        };
        class 42nd_CVT_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_cvt";
        };
        class 42nd_NCO_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_nco";
        };
        class 42nd_EOD_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_eod";
        };
        class 42nd_EOD_Vet_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_eod_vet";
        };
        class 42nd_Rose_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_rose";
        };
        class 42nd_Hound_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_hound";
        };
        class 42nd_Walker_Trooper_Uniform
        {
            model = "Para42_Uniforms";
            uniform = "u_walker";
        };

        class 42nd_3AS_DC15A_F
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a";
            tag = "as3";
        };
        class 42nd_3AS_DC15A_GL
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a_gl";
            tag = "as3";
        };
        class 42nd_3AS_DC15C_F
        {
            model = "Para42_Weapons";
            weapon = "w_dc15c";
            tag = "as3";
        };
        class 42nd_3AS_DC15C_GL
        {
            model = "Para42_Weapons";
            weapon = "w_dc15c_gl";
            tag = "as3";
        };
        class 42nd_3AS_DC15S_F
        {
            model = "Para42_Weapons";
            weapon = "w_dc15s";
            tag = "as3";
        };
        class 42nd_3AS_DC15S_GL
        {
            model = "Para42_Weapons";
            weapon = "w_dc15s_gl";
            tag = "as3";
        };
        class 42nd_3AS_DC17S_Dual_F
        {
            model = "Para42_Weapons";
            weapon = "w_dc17s_dual";
            tag = "as3";
        };
        class 42nd_3AS_DC17S_F
        {
            model = "Para42_Weapons";
            weapon = "w_dc17s";
            tag = "as3";
        };
        class 42nd_3AS_DLT19
        {
            model = "Para42_Weapons";
            weapon = "w_dlt19";
            tag = "as3";
        };
        class 42nd_3AS_DP23_GL
        {
            model = "Para42_Weapons";
            weapon = "w_dp23_gl";
            tag = "as3";
        };
        class 42nd_3AS_FusionCutter_F
        {
            model = "Para42_Weapons";
            weapon = "w_fusioncutter";
            tag = "as3";
        };
        class 42nd_773Firepuncher
        {
            model = "Para42_Weapons";
            weapon = "w_773firepuncher";
            tag = "ida";
        };
        class 42nd_774CX
        {
            model = "Para42_Weapons";
            weapon = "w_774cx";
            tag = "ida";
        };
        class 42nd_DC15A
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a";
            tag = "ida";
        };
        class 42nd_DC15LE
        {
            model = "Para42_Weapons";
            weapon = "w_dc15le";
            tag = "ida";
        };
        class 42nd_DC15P
        {
            model = "Para42_Weapons";
            weapon = "w_dc15p";
            tag = "ida";
        };
        class 42nd_DC15S
        {
            model = "Para42_Weapons";
            weapon = "w_dc15s";
            tag = "ida";
        };
        class 42nd_DC15S_UGL
        {
            model = "Para42_Weapons";
            weapon = "w_dc15s_gl";
            tag = "ida";
        };
        class 42nd_DC15X
        {
            model = "Para42_Weapons";
            weapon = "w_dc15x";
            tag = "ida";
        };
        class 42nd_DC17
        {
            model = "Para42_Weapons";
            weapon = "w_dc17";
            tag = "ida";
        };
        class 42nd_DLT15
        {
            model = "Para42_Weapons";
            weapon = "w_dlt15";
            tag = "ida";
        };
        class 42nd_DLT19
        {
            model = "Para42_Weapons";
            weapon = "w_dlt19";
            tag = "ida";
        };
        class 42nd_DLT19D
        {
            model = "Para42_Weapons";
            weapon = "w_dlt19d";
            tag = "ida";
        };
        class 42nd_FA11
        {
            model = "Para42_Weapons";
            weapon = "w_fa11";
            tag = "ida";
        };
        class 42nd_Galaar90
        {
            model = "Para42_Weapons";
            weapon = "w_galaar90";
            tag = "ida";
        };
        class 42nd_IQA11
        {
            model = "Para42_Weapons";
            weapon = "w_iqa11";
            tag = "ida";
        };
        class 42nd_JLTS_DC15A
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a";
            tag = "jlts";
        };
        class 42nd_JLTS_DC15A_plastic
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a_plastic";
            tag = "jlts";
        };
        class 42nd_JLTS_DC15A_ugl
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a_gl";
            tag = "jlts";
        };
        class 42nd_JLTS_DC15A_ugl_plastic
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a_gl_plastic";
            tag = "jlts";
        };
        class 42nd_JLTS_DC15S
        {
            model = "Para42_Weapons";
            weapon = "w_dc15s";
            tag = "jlts";
        };
        class 42nd_JLTS_DC15X
        {
            model = "Para42_Weapons";
            weapon = "w_dc15x";
            tag = "jlts";
        };
        class 42nd_JLTS_DW32S
        {
            model = "Para42_Weapons";
            weapon = "w_dw32s";
            tag = "jlts";
        };
        class 42nd_JLTS_Z6
        {
            model = "Para42_Weapons";
            weapon = "w_z6";
            tag = "jlts";
        };
        class 42nd_ls_weapon_dc15a
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc15a_wooden
        {
            model = "Para42_Weapons";
            weapon = "w_dc15a_wooden";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc15ac
        {
            model = "Para42_Weapons";
            weapon = "w_dc15ac";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc15br
        {
            model = "Para42_Weapons";
            weapon = "w_dc15br";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc15br_wooden
        {
            model = "Para42_Weapons";
            weapon = "w_dc15br_wooden";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc15s
        {
            model = "Para42_Weapons";
            weapon = "w_dc15s";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc15sa
        {
            model = "Para42_Weapons";
            weapon = "w_dc15sa";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc15x
        {
            model = "Para42_Weapons";
            weapon = "w_dc15x";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc17s
        {
            model = "Para42_Weapons";
            weapon = "w_dc17s";
            tag = "ls";
        };
        class 42nd_ls_weapon_dc17s_dual
        {
            model = "Para42_Weapons";
            weapon = "w_dc17s_dual";
            tag = "ls";
        };
        class 42nd_ls_weapon_firepuncher
        {
            model = "Para42_Weapons";
            weapon = "w_firepuncher";
            tag = "ls";
        };
        class 42nd_ls_weapon_z6
        {
            model = "Para42_Weapons";
            weapon = "w_z6";
            tag = "ls";
        };
        class 42nd_RPS6
        {
            model = "Para42_Weapons";
            weapon = "w_rps6";
            tag = "ida";
        };
        class 42nd_Valken38X
        {
            model = "Para42_Weapons";
            weapon = "w_valken38x";
            tag = "as3";
        };
        class 42nd_Z6
        {
            model = "Para42_Weapons";
            weapon = "w_z6";
            tag = "ida";
        };
    };
};
