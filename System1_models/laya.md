###  General notes
- The English Laya checkpoint uses a bidirectional ModernBERT encoder with decision heads; the multilingual checkpoint uses mmBERT.
- State is not encoded once and freely reused rather everytime it is computed again.So do not send questions that are dependent on each other's outputs in one call rather make subsequent calls.
- There are 3 types of questions atm: Choice, Score, and Noul
- Needs very specific context and any added information negatively impacts the results(way more than usal Language models)
- Different available checkpoints for this atm.
| Checkpoint | Encoder and size | Default context | Best starting point |
|---|---|---|---|
| laya | ModernBERT-large, about 421M parameters | 512 tokens | English decision workloads. |
| laya-multilingual | mmBERT-base, about 322M parameters | 1,024 tokens | Non-English or mixed-language traffic. |
| laya-typed-decisions | ModernBERT-large, about 421M parameters | 1,024 tokens | Workflows resembling its typed-decisions training tasks. |

### Flow of information in Laya:

```mermaid
flowchart TD
    Q["Question<br/>Which department should handle this?"]
    O["Options<br/>billing · technical"]
    C["Context<br/>I was charged twice."]

    Q --> S
    O --> S
    C --> S

    S["Build one token sequence<br/>[CLS] type + question [SEP]<br/>[MASK] billing [MASK] technical [SEP]<br/>context [SEP]"]

    S --> B["ModernBERT encoder<br/>Processes the entire sequence together"]
    B --> V["One contextual vector per token<br/>Question, options, and context interact through attention"]

    subgraph H["Decision head"]
        V --> T["Add the learned question-type vector<br/>Here: choice"]
        T --> L["Additional Transformer layers<br/>Refine all token vectors"]
        L --> M["Extract the vectors at the two [MASK] positions"]
        M --> MB["Billing marker vector"]
        M --> MT["Technical marker vector"]
        MB --> SB["Shared scoring network<br/>Produces billing logit"]
        MT --> ST["Same scoring network<br/>Produces technical logit"]
    end

    SB --> P["Temperature scaling + softmax<br/>Convert logits into option probabilities"]
    ST --> P
    P --> A["Choose the highest-probability option<br/>Return choice + probability distribution"]
```